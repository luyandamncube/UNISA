function successive_over_relaxation()

    % % Parse command line arguments
    % if nargin != 3
    %     printf("Usage: octave 009_successive_over_relaxation.m <matrix_A> <vector_b> <omega>\n");
    %     printf("Example: octave 009_successive_over_relaxation.m '[2 0 0; -1 1 0; 3 2 -1]' '[-1; 3; 0]' 0.3\n");
    %     return;
    % end

    % Convert input arguments to numerical matrices/vectors
    A = eval(argv(){1});  % Coefficient matrix
    b = eval(argv(){2});  % Right-hand side vector
    omega = str2num(argv(){3});  % Relaxation factor

    % Display the input matrices and vectors
    printf("Input Matrix A:\n");
    disp(A);
    printf("Input Vector b:\n");
    disp(b);
    printf("Relaxation factor omega: %.2f\n\n", omega);

    % Initialize parameters
    x = zeros(size(b));  % Initial guess
    max_iterations = 100;
    tol = 1e-6;
    
    % Print the system of equations
    printf("The system of equations (Ax = b) is:\n");
    for i = 1:length(b)
        equation = sprintf('%.2f * x1 + %.2f * x2 + %.2f * x3 = %.2f', A(i, 1), A(i, 2), A(i, 3), b(i));
        printf("Equation %d: %s\n", i, equation);
    end
    printf("\n");

    % SOR Iteration
    for iter = 1:max_iterations
        x_old = x;  % Store the old values for debugging

        printf("Iteration: ============================ %d:\n", iter);
        
        % Update each variable
        for i = 1:length(b)
            sum = b(i);  % Start with the right-hand side value
            for j = 1:length(b)
                if j != i
                    sum = sum - A(i, j) * x_old(j);  % Use the old value of x
                end
            end
            % Calculate the new value for x[i]
            x(i) = (1 - omega) * x_old(i) + (omega / A(i, i)) * sum;  % Update x

            % Debugging output for current update
            printf("Update for x[%d]:\n", i);
            printf("x[%d] = (1 - %.2f) * %.4f + (%.2f / %.2f) * (%.4f - ", ...
                i, omega, x_old(i), omega, A(i, i), sum);
            for j = 1:length(b)
                if j != i
                    printf("%.2f * x[%d] ", A(i, j), j);
                    if j < length(b)
                        printf("+ ");
                    end
                end
            end
            printf(")\n");
            printf("Result: x[%d] = %.4f\n\n", i, x(i));
        end

        
        % Check for convergence
        if norm(x - x_old, inf) < tol
            fprintf('Converged to solution:\n');
            disp(x);
            return;
        end
    end

    fprintf('Maximum number of iterations reached without convergence.\n');
end

% % Uncomment the following line if you want to execute the method directly
successive_over_relaxation()
