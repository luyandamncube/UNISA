function gauss_seidel_method()

    % % Parse command line arguments
    % if nargin != 2
    %     printf("Usage: octave 007_gauss_seidel.m <matrix> <b>\n");
    %     printf("Example: octave 007_gauss_seidel.m '[4 1 -1; 1 3 2; -1 2 5]' '[7; 13; 2]'\n");
    %     return;
    % end

    % Convert input arguments to numerical matrices
    A = eval(argv(){1});  % Coefficient matrix
    b = eval(argv(){2});  % Right-hand side vector

    [n, m] = size(A);
    if n != m
        error('Matrix must be square for Gauss-Seidel method.');
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

    % Gauss-Seidel Iteration
    while iter < max_iterations
        x_new = x;  % Copy current values

        % Update each variable
        for i = 1:n
            sum = b(i);  % Start with the right-hand side value
            for j = 1:n
                if j != i
                    sum = sum - A(i, j) * x_new(j);  % Use the updated value of x
                end
            end
            x_new(i) = sum / A(i, i);  % Update the current variable

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
gauss_seidel_method()