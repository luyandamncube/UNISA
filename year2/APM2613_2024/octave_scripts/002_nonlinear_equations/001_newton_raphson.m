function newton_raphson_method()

    % Parse command line arguments
    % if nargin != 5
    %     printf("Usage: octave 001_newton_raphson.m <function_definition> <derivative_definition> <initial_guess> <tol> <max_iterations>\n");
    %     printf("Example: octave 001_newton_raphson.m '3*x^3 - 10*x^2 + 13/4 + 15/2' '9*x^2 - 20*x' 1 1e-6 100\n");
    %     return;
    % end

    % Convert input arguments to numerical values
    f_str = argv(){1};
    df_str = argv(){2};  % Derivative function
    x0 = str2num(argv(){3});
    tol = str2num(argv(){4});
    max_iterations = str2num(argv(){5});

    % Define the function f(x) and its derivative f'(x) using the input strings
    f = str2func(['@(x)' f_str]);
    df = str2func(['@(x)' df_str]);

    % Initialize iteration counter
    iter = 0;

    % Debugging output for initial values
    printf("f:\t\t %s\n", f_str);
    printf("f'(x):\t\t %s\n", df_str);
    printf("Initial guess:\tx0 = %f\n", x0);
    printf("Tolerance:\t %e\n", tol);
    printf("Max iterations:\t %d\n\n", max_iterations);

    % Newton-Raphson Iteration
    while iter < max_iterations
        % Evaluate function and its derivative at current guess
        fx0 = f(x0);
        dfx0 = df(x0);

        % Check for division by zero
        if abs(dfx0) < eps
            error('Derivative is too close to zero. Method may fail.');
        end

        % Calculate the next approximation
        x1 = x0 - fx0 / dfx0;

        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Iteration: %d\n", iter + 1);
        printf("f(x0) = %f, f'(x0) = %f\n", fx0, dfx0);
        printf("Next approximation: x1 = %f\n", x1);

        % Check for convergence
        if abs(x1 - x0) < tol
            fprintf('Converged to root: %f after %d iterations\n', x1, iter + 1);
            return;
        end

        % Update guess for the next iteration
        x0 = x1;

        % Increment iteration counter
        iter = iter + 1;
    end

    % Final output
    if iter == max_iterations
        fprintf('Maximum number of iterations reached without convergence.\n');
    else
        fprintf('Final approximation: %f after %d iterations\n', x1, iter);
    end
end

% % Uncomment the following line if you want to execute the method directly
newton_raphson_method()
