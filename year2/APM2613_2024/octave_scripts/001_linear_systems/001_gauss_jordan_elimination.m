function gauss_jordan_elimination()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 001_gauss_jordan_elimination.m <augmented_matrix>\n");
    %     printf("Example: octave 001_gauss_jordan_elimination.m '[1 2 -1 3; 2 3 3 15; 3 2 1 10]'\n");
    
    % MATRIX
    % 1st row : 1x + 2y - 1z = 3 
    % 2nd row : 2x + 2y + 3z = 15
    % 3rd row : 3x + 2y + 1z = 10
   
    %     return;
    % end

    % Convert input argument to numerical matrix
    A = eval(argv(){1});  % Augmented matrix

    [rows, cols] = size(A);
    n = rows;

    printf("Augmented Matrix:\n");
    disp(A);
    printf("\n");

    % Gauss-Jordan elimination
    for i = 1:n
        % Partial pivoting
        [~, max_index] = max(abs(A(i:n, i)));
        max_index = max_index + i - 1;  % Adjust index
        if max_index != i
            % Swap rows
            A([i, max_index], :) = A([max_index, i], :);
            printf("Swapped row %d with row %d for pivoting.\n", i, max_index);
            disp(A);
        end

        % Normalize the pivot row
        A(i, :) = A(i, :) / A(i, i);
        printf("Normalized row %d:\n", i);
        disp(A);
        
        % Eliminate other rows
        for j = 1:n
            if j != i
                A(j, :) = A(j, :) - A(j, i) * A(i, :);
                printf("Updated row %d using row %d:\n", j, i);
                disp(A);
            end
        end
        
        printf("\n");
    end

    % Final output
    fprintf('Reduced Row Echelon Form:\n');
    disp(A);
    fprintf('Solution:\n');
    solution = A(:, end);
    disp(solution);
end

% % Uncomment the following line if you want to execute the method directly
gauss_jordan_elimination()
