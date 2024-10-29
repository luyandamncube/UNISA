function newton_raphson_equations()

    % % Parse command line arguments
    % if nargin != 3
    %     printf("Usage: octave 001_newton_raphson_2d.m <equation1> <equation2> <initial_guess>\n");
    %     printf("Example: octave 001_newton_raphson_2d.m 'x^2 + y - x' 'x*y + 2*y - 1' '[0; 0]'\n");
    %     return;
    % end

    % Extract the equations from the input arguments
    eq1_str = argv(){1};  % First equation
    eq2_str = argv(){2};  % Second equation
    initial_guess = eval(argv(){3});  % Initial guess for x and y

    % Define the functions based on input strings
    f1 = @(x, y) eval(eq1_str);  % Evaluate first equation
    f2 = @(x, y) eval(eq2_str);  % Evaluate second equation

    % Tolerance and maximum iterations
    tol = 1e-6;   % Tolerance for convergence
    max_iterations = 100;

    % Newton-Raphson Iteration
    for iter = 1:max_iterations
        % Evaluate the function values
        F = [f1(initial_guess(1), initial_guess(2)); f2(initial_guess(1), initial_guess(2))];
        
        % Jacobian matrix definition
        J = [
            (2*initial_guess(1) - 1), 1;  % Partial derivative of f1
            initial_guess(2), initial_guess(1) + 2   % Partial derivative of f2
        ];
        
        % Check for singularity
        if det(J) == 0
            error('Jacobian is singular at the current guess.');
        end
        
        % Calculate the inverse of the Jacobian for debugging
        J_inv = inv(J);
        
        % Solve for the update step
        delta = -J \ F;  % Use backslash operator for solving

        % Update the guess
        initial_guess = initial_guess + delta;

        % Debugging output
        printf("Iteration: %d\n", iter);
        printf("Current guess: [x, y] = [%f, %f]\n", initial_guess(1), initial_guess(2));
        printf("Function evaluations: F1 = %f, F2 = %f\n", F(1), F(2));
        printf("Jacobian matrix J:\n");
        disp(J);
        printf("Inverse of Jacobian J_inv:\n");
        disp(J_inv);
        printf("Newton's Iteration Formula: x_new = x_old + delta\n");
        printf("Matrix delta:\n");
        disp(delta);
        printf("Updated guess after iteration: [x, y] = [%f, %f]\n\n", initial_guess(1), initial_guess(2));

        % Check for convergence
        if norm(delta) < tol
            fprintf('Converged to solution:\n');
            disp(initial_guess);
            return;
        end
    end

    fprintf('Maximum number of iterations reached without convergence.\n');
end

% % Uncomment the following line if you want to execute the method directly
newton_raphson_equations()
