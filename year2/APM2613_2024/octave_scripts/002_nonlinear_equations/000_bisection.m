function bisection_method()

    % Parse command line arguments
    % if nargin != 5
    %     printf("Usage: octave 000_bisection.m <function_definition> <a> <b> <tol> <max_iterations>\n");
    %     printf("Example: octave 000_bisection.m '3*x^3 - 10*x^2 + 13/4 + 15/2' 0 2 1e-6 100\n");
    %     return;
    % end

    printf("f:\t\t %s\n", argv(){1});
    printf("a:\t\t %s\n", argv(){2});
    printf("b:\t\t %s\n", argv(){3});
    printf("tol:\t\t %s\n", argv(){4});
    printf("max_iterations:\t\t %s\n\n", argv(){5});

    % Convert input arguments to numerical values
    f_str = argv(){1};
    a = str2num(argv(){2});
    b = str2num(argv(){3});
    tol = str2num(argv(){4});
    max_iterations = str2num(argv(){5});

    % Define the function f(x) using the input string
    f = str2func(['@(x)' f_str]);

    % Initialize iteration counter
    iter = 0;

    % Check if the function changes sign within the interval
    if f(a) * f(b) >= 0
        error('Function does not change sign within the interval');
    else
        printf("[1] Initialize the interval [a,b]\n");
        printf("\tFunction changes sign within the interval\n");
        printf("\tf(a): %f \n", f(a));
        printf("\tf(b): %f \n", f(b));
        printf("\n");
    end

    % Initialize the error and width of the interval
    width = b - a;

    % Iterate until convergence or max_iterations reached
    while width > tol && iter < max_iterations
        % Compute midpoint of the interval
        c = (a + b) / 2;

        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Iteration: %d\n", iter + 1);
        printf("[2] Calculate the midpoint:\n");
        printf("\tc = (a + b) / 2 = %f\n", c);
        
        % Evaluate function at midpoint
        fc = f(c);
        printf("[3] Evaluate f(c) = f(%f) = %f\n", c, fc);
        
        % Check if the midpoint is the root
        if abs(fc) < tol
            fprintf('Root found: %f after %d iterations\n', c, iter + 1);
            return;
        end
        
        % Update interval based on the sign of f(c)
        if f(a) * fc < 0
            b = c; % Root lies in the left half
            printf("Root lies in the left half of the interval [a, c]\n");
        else
            a = c; % Root lies in the right half
            printf("Root lies in the right half of the interval [c, b]\n");
        end
        
        % Update width of the interval and iteration count
        width = b - a;
        iter = iter + 1;

        printf("Updated interval: [%f, %f] with width = %f\n", a, b, width);
        printf("\n");
    end

    % Final output
    if iter == max_iterations
        fprintf('Maximum number of iterations reached without convergence.\n');
    else
        fprintf('Converged to root: %f after %d iterations\n', (a + b) / 2, iter);
    end
end

% % Uncomment the following line if you want to execute the method directly
bisection_method()
