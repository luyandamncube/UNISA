function newtons_method()
    % Convert command-line arguments to functions
    func_str = argv(){1};
    func_derivative_str = argv(){2};
    func = str2func(['@(x)' func_str]);
    func_derivative = str2func(['@(x)' func_derivative_str]);

    % Convert other command-line arguments to numerical values
    initial_guess = str2double(argv(){3});
    tolerance = str2double(argv(){4});
    max_iterations = str2double(argv(){5});

    % Call the Newton's method function to find the root
    [solution,no_iterations] = newtons(func, func_derivative, initial_guess, tolerance, max_iterations);

    if no_iterations > 0   % Solution found
        printf("[5] Repeat steps 3-4 until convergence, stop\n");
        printf("\tno. of iterations: %d\n",no_iterations+1);
        printf("\n");
        fprintf('A solution is: %f\n', solution)
    else
        fprintf('Abort execution.\n')
    end
end

function [solution,no_iterations] = newtons(func, func_derivative, initial_guess, tolerance, max_iterations)
    printf("f:\t\t\t %s\n", argv(){1});
    printf("f_derivative:\t\t %s\n", argv(){2});
    printf("initial_guess:\t\t %s\n", argv(){3});
    printf("tolerance:\t\t %s\n", argv(){4});
    printf("max_iterations:\t\t %s\n", argv(){5});
    printf("\n");
    % Initialize variables
    x = initial_guess;
    iter = 0;
    
    % Iterate until convergence or maximum iterations reached
    while iter < max_iterations
        printf("-------------------------------------------------------- iter: %d\n",iter)
        printf("[2] Calculate the midpoint:\n");
        printf("\tx_0 = %d\n",x);
        % Evaluate function and its derivative at current guess
        fx = func(x);
        fx_derivative = func_derivative(x);
        
        printf("[3] Evaluate f(c) & f'(c)\n");
        printf("\tf(x_0):\t\t%d \n", fx);
        printf("\tf'(x_0):\t%d \n", fx_derivative);
        % Update guess using Newton's method formula
        x = x - fx / fx_derivative;
        printf("\tx_1:\t\t%d \n", x);

        printf("[4] Evaluate f(c)\n");
        printf("\tif f(x_0) then x_0 is an exact root\n");
        % Check for convergence
        if abs(fx) < tolerance
            solution = x;
            no_iterations = iter;
            return;
        end
        % Increment iteration count
        iter = iter + 1;
    end
    % If maximum iterations reached without convergence
    if iter == max_iterations
        warning('Maximum number of iterations reached without convergence');
        solution = NaN;
        no_iterations = iter;
    end
    no_iterations = iter;

end

% Parse command-line arguments
if nargin != 5
    printf("Usage: octave 000_bisection.m func func_derivative initial_guess tolerance max_iterations\n");
    printf("Example: octave 000_bisection.m '3*x^3 - 10*x^2 + 13/4 + 15/2' 0 2 1e-6 100\n");
    return;
endif

newtons_method()