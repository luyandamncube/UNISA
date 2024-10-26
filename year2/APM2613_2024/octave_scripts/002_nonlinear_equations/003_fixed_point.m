function fixed_point_method()
 
    % Parse command line arguments
    % if nargin != 4
    %     printf("Usage: octave 003_fixed_point.m <function_definition> <initial_guess> <tol> <max_iterations>\n");
    %     printf("Example: octave 003_fixed_point.m 'cos(x)' 0 1e-6 100\n");
    %     return;
    % end
    
    printf("f:\t\t %s\n", argv(){1});
    printf("a:\t\t %s\n", argv(){2});
    printf("b:\t\t %s\n", argv(){3});
    printf("tol:\t\t %s\n", argv(){4});
    % Convert input arguments to numerical values
    f_str = argv(){1};
    x0 = str2num(argv(){2});
    tol = str2num(argv(){3});
    max_iterations = str2num(argv(){4});
    % Define the function f(x) using the input string
    f = str2func(['@(x)' f_str]);
    
    % Initialize iteration counter
    iter = 0;
    
    % Initialize the error for the first iteration
    error = Inf;
    
    printf("f:\t\t %s\n", f_str);
    printf("Initial guess:\t %f\n", x0);
    printf("Tolerance:\t %e\n", tol);
    printf("Max iterations:\t %d\n\n", max_iterations);
    
    % Fixed-Point Iteration
    while error > tol && iter < max_iterations
        x1 = f(x0);  % Update x using the fixed-point formula
        
        % Calculate the error
        error = abs(x1 - x0);
        
        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Iteration: %d\n", iter + 1);
        printf("Select interval: [x0, f(x0)] = [%f, %f]\n", x0, x1);
        printf("Evaluate function: f(x0) = %f\n", x1);
        printf("Check function: f(x0) = f(%f) = %f\n", x0, x1);
        
        % Update the guess
        x0 = x1;
        
        printf("Update guess: x0 = %f\n", x0);
        printf("Current error: %e\n", error);
        printf("\n");
        
        iter = iter + 1;  % Increment iteration counter
    end
    
    % Final output
    if error <= tol
        fprintf('Converged to: %f after %d iterations\n', x0, iter);
    else
        fprintf('Max iterations reached without convergence.\n');
    end
end

% % Uncomment the following line if you want to execute the method directly
fixed_point_method()
