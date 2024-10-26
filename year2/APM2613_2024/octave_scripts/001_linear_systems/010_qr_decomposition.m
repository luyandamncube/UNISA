function qr_decomposition()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 010_qr_decomposition.m <matrix>\n");
    %     printf("Example: octave 010_qr_decomposition.m '[1 2; 3 4; 5 6]'\n");
    %     return;
    % end

    % Convert input argument to numerical matrix
    A = eval(argv(){1});  % Input matrix

    [m, n] = size(A);
    
    printf("Input Matrix A:\n");
    disp(A);
    printf("\n");

    % Initialize Q and R matrices
    Q = zeros(m, n);
    R = zeros(n, n);

    % QR Decomposition using Gram-Schmidt process
    for j = 1:n
        % Start with the j-th column of A
        v = A(:, j);
        
        % Subtract the projections onto the previous basis vectors
        for i = 1:j-1
            R(i, j) = Q(:, i)' * A(:, j);  % Compute R[i,j]
            v = v - R(i, j) * Q(:, i);  % Subtract the projection
        end
        
        % Compute the norm and normalize v to get the j-th column of Q
        R(j, j) = norm(v);
        Q(:, j) = v / R(j, j);
        
        % Debugging output
        printf("--------------------------------------------------------\n");
        printf("Step %d:\n", j);
        printf("Current vector v:\n");
        disp(v);
        printf("Normalized Q(:, %d):\n", j);
        disp(Q(:, j));
        printf("R matrix after updating column %d:\n", j);
        disp(R);
    end

    % Final output
    printf("Final Q matrix:\n");
    disp(Q);
    printf("Final R matrix:\n");
    disp(R);
    
    % Verify the result by multiplying Q and R
    QR = Q * R;
    printf("Product of Q and R:\n");
    disp(QR);
    
    if norm(QR - A) < 1e-10
        printf("QR decomposition is verified: Q * R = A\n");
    else
        printf("QR decomposition verification failed!\n");
    end
end

% % Uncomment the following line if you want to execute the method directly
qr_decomposition()
