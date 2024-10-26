function jacobi_method()

    % Parse command line arguments
    % if nargin != 2
    %     printf("Usage: octave 006_jacobi.m <matrix> <b>\n");
    %     printf("Example: octave 006_jacobi.m '[4 1 -1; 1 3 2; -1 2 5]' '[7; 13; 2]'\n");
    %     return;
    % end

    % Convert input arguments to numerical matrices
    A = eval(argv(){1});  % Coefficient matrix
    b = eval(argv(){2});  % Right-hand side vector

    [n, m] = size(A);
    if n != m
        error('Matrix must be square for Jacobi method.');
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
    max_iterations = 100;
    tol = 1e-6;
    iter = 0;

    % Jacobi Iteration
    while iter < max_iterations
        x_new = zeros(n, 1);  % New approximation

        % Update each variable
        for i = 1:n
            sum = 0;
            for j = 1:n
                if j != i
                    sum = sum + A(i, j) * x(j);
                end
            end
            x_new(i) = (b(i) - sum) / A(i, i);

            % Debugging output
            printf("Iteration: %d, Updating x[%d]: %f\n", iter + 1, i, x_new(i));
        end

        % Check for convergence
        if norm(x_new - x, inf) < tol
            fprintf('Converged to solution:\n');
            disp(x_new);
            return;
        end

        % Update for the next iteration
        x = x_new;
        iter = iter + 1;

        % Print current approximation
        printf("Current approximation after iteration %d:\n", iter);
        disp(x);
        printf("\n");
    end

    fprintf('Maximum number of iterations reached without convergence.\n');
end

% % Uncomment the following line if you want to execute the method directly
jacobi_method()
