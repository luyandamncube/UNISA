function lu_factorization()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 005_lu_factorization.m <matrix>\n");
    %     printf("Example: octave 005_lu_factorization.m '[4 3; 6 3]'\n");
    %     return;
    % end

    % Convert input argument to numerical matrix
    A = eval(argv(){1});  % Input square matrix

    [n, m] = size(A);

    if n != m
        error('Matrix must be square for LU factorization.');
    end

    printf("Input Matrix A:\n");
    disp(A);
    printf("\n");

    % Initialize L and U matrices
    L = eye(n); % L is initialized to the identity matrix
    U = zeros(n); % U is initialized to zeros

    % Perform LU factorization
    for i = 1:n
        for j = i:n
            U(i, j) = A(i, j) - L(i, 1:i-1) * U(1:i-1, j); % Compute U
        end
        for j = i+1:n
            L(j, i) = (A(j, i) - L(j, 1:i-1) * U(1:i-1, i)) / U(i, i); % Compute L
        end

        % Debugging output
        printf("Step %d:\n", i);
        printf("Matrix L:\n");
        disp(L);
        printf("Matrix U:\n");
        disp(U);
        printf("\n");
    end

    % Final output
    printf("Final L matrix:\n");
    disp(L);
    printf("Final U matrix:\n");
    disp(U);
    
    % Verify the result by multiplying L and U
    LU = L * U;
    printf("Product of L and U:\n");
    disp(LU);
    
    if norm(LU - A) < 1e-10
        printf("LU factorization is verified: L * U = A\n");
    else
        printf("LU factorization verification failed!\n");
    end
end

% % Uncomment the following line if you want to execute the method directly
lu_factorization()
