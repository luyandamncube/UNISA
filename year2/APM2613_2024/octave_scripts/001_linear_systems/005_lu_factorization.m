function lu_factorization_with_inputs()

    % Parse command line arguments
    % if nargin != 4
    %     printf("Usage: octave 005_lu_factorization_with_inputs.m <matrix_L> <matrix_U> <vector_y> <vector_b>\n");
    %     printf("Example: octave 005_lu_factorization_with_inputs.m '[2 0 0; -1 1 0; 3 2 -1]' '[1 1 1; 0 1 2; 0 0 1]' '[x1; x2; x3]' '[-1; 3; 0]'\n");
    %     return;
    % end

    % Convert input arguments to numerical matrices/vectors
    L = eval(argv(){1});  % Lower triangular matrix L
    U = eval(argv(){2});  % Upper triangular matrix U
    y = zeros(size(U, 1), 1);  % Placeholder for y vector
    b = eval(argv(){4});  % Vector of constants b

    % Display the input matrices and vectors
    printf("Input Matrix L:\n");
    disp(L);
    printf("Input Matrix U:\n");
    disp(U);
    printf("Input Vector b:\n");
    disp(b);
    printf("\n");

    % Verify sizes
    [n, m] = size(L);
    if n != m
        error('Matrix L must be square.');
    end

    if size(U, 1) != n || size(U, 2) != n
        error('Matrix U must be square and the same size as L.');
    end
    
    if length(b) != n
        error('Vector b must have the same number of elements as the rows of L and U.');
    end

    % Solve Ly = b using forward substitution
    y_solution = zeros(n, 1);
    printf("Forward substitution steps (Ly = b):\n");
    for i = 1:n
        % Calculate the current value of y
        y_solution(i) = (b(i) - L(i, 1:i-1) * y_solution(1:i-1)) / L(i, i);
        
        % Debugging output for current step
        printf("Step %d: y[%d] = (b[%d] - L[%d, 1:%d] * y[1:%d]) / L[%d, %d]\n", ...
               i, i, i, i, i-1, i-1, i, i);
        printf("   = (%.4f - %.4f) / %.4f\n", b(i), L(i, 1:i-1) * y_solution(1:i-1), L(i, i));
        printf("   y[%d] = %.4f\n\n", i, y_solution(i));
    end

    % Output for y
    printf("Solution for y (Ly = b):\n");
    disp(y_solution);

    % Now solve Ux = y using back substitution
    x = zeros(n, 1);
    printf("Back substitution steps (Ux = y):\n");
    for i = n:-1:1
        % Calculate the current value of x
        x(i) = (y_solution(i) - U(i, i+1:n) * x(i+1:n)) / U(i, i);
        
        % Debugging output for current step
        printf("Step %d: x[%d] = (y_solution[%d] - U[%d, %d:%d] * x[%d:%d]) / U[%d, %d]\n", ...
               n-i+1, i, i, i, i+1, n, i+1, n, i, i);
        printf("   = (%.4f - %.4f) / %.4f\n", y_solution(i), U(i, i+1:n) * x(i+1:n), U(i, i));
        printf("   x[%d] = %.4f\n\n", i, x(i));
    end

    % Final output
    printf("Final solution x (Ux = y):\n");
    disp(x);
end

% % Uncomment the following line if you want to execute the method directly
lu_factorization_with_inputs()
