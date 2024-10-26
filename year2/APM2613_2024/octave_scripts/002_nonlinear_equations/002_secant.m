function secant_method()

    % Parse command line arguments
    % if nargin != 5
    %     printf("Usage: octave 002_secant.m <function_definition> <x0> <x1> <tol> <max_iterations>\n");
    %     printf("Example: octave 002_secant.m '3*x^3 - 10*x^2 + 13/4 + 15/2' 0 2 1e-6 100\n");
    %     return;
    % end

    % Convert input arguments to numerical values
    f_str = argv(){1};
    x0 = str2num(argv(){2});
    x1 = str2num(argv(){3});
    tol = str2num(argv(){4});
    max_iterations = str2num(argv(){5});

    % Define the function f(x) using the input string
    f = str2func(['@(x)' f_str]);

    % Initialize iteration counter
    iter = 0;

    % Debugging output for initial values
    printf("f:\t\t %s\n", f_str);
    printf("Initial guesses:\tx0 = %f, x1 = %f\n", x0, x1);
    printf("Tolerance:\t %e\n", tol);
    printf("Max iterations:\t %d\n\n", max_iterations);

    % Iterate using the Secant Method
    while iter < max_iterations
        % Evaluate function at current guesses
        f0 = f(x0);
        f1 = f(x1);

        % Check for division by zero
        if abs(f1 - f0) < eps
            error('Function values at guesses are too close. Cannot proceed.');
        end

        % Calculate the next approximation
        x2 = x1 - f1 * ((x1 - x0) / (f1 - f0));

        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Iteration: %d\n", iter + 1);
        printf("Evaluate: f(x0) = %f, f(x1) = %f\n", f0, f1);
        printf("Next approximation: x2 = %f\n", x2);

        % Check for convergence
        if abs(x2 - x1) < tol
            fprintf('Converged to root: %f after %d iterations\n', x2, iter + 1);
            return;
        end

        % Update guesses for the next iteration
        x0 = x1;
        x1 = x2;

        % Increment iteration counter
        iter = iter + 1;
    end

    % Final output
    if iter == max_iterations
        fprintf('Maximum number of iterations reached without convergence.\n');
    else
        fprintf('Final approximation: %f after %d iterations\n', x2, iter);
    end
end

% % Uncomment the following line if you want to execute the method directly
secant_method()
