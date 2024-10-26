function conjugate_gradient_method()

    % Parse command line arguments
    % if nargin != 2
    %     printf("Usage: octave 008_conjugate_gradient.m <matrix> <b>\n");
    %     printf("Example: octave 008_conjugate_gradient.m '[4 1; 1 3]' '[1; 2]'\n");
    %     return;
    % end

    % Convert input arguments to numerical matrices
    A = eval(argv(){1});  % Coefficient matrix
    b = eval(argv(){2});  % Right-hand side vector

    [n, m] = size(A);
    if n != m
        error('Matrix must be square for Conjugate Gradient method.');
    end

    if length(b) != n
        error('The dimensions of b must match the number of rows in A.');
    end

    printf("Coefficient Matrix A:\n");
    disp(A);
    printf("Right-hand side vector b:\n");
    disp(b);
    printf("\n");

    % Initialize parameters
    x = zeros(n, 1);  % Initial guess
    r = b - A * x;    % Initial residual
    p = r;            % Initial direction
    iter = 0;
    tol = 1e-6;
    max_iterations = 100;

    % Conjugate Gradient Iteration
    while iter < max_iterations
        rs_old = r' * r;  % Old residual squared

        % Calculate alpha
        Ap = A * p;  % A multiplied by direction p
        alpha = rs_old / (p' * Ap);
        
        % Update the solution
        x = x + alpha * p;
        
        % Update the residual
        r = r - alpha * Ap;
        
        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Iteration: %d\n", iter + 1);
        printf("Alpha: %f\n", alpha);
        printf("Updated solution x:\n");
        disp(x);
        printf("Updated residual r:\n");
        disp(r);
        
        % Check for convergence
        if sqrt(r' * r) < tol
            fprintf('Converged to solution:\n');
            disp(x);
            return;
        end

        % Calculate beta
        rs_new = r' * r;  % New residual squared
        beta = rs_new / rs_old;
        
        % Update the direction
        p = r + beta * p;
        
        iter = iter + 1;
    end

    fprintf('Maximum number of iterations reached without convergence.\n');
end

% % Uncomment the following line if you want to execute the method directly
conjugate_gradient_method()
