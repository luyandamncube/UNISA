function gaussian_elimination_scaled_partial_pivoting()

    % disp(augmented_matrix);
    solution = gaussian_elimination();
    disp(solution);
end

function x = gaussian_elimination()
    A = argv(){1};
    b = argv(){2};
    % Augment A with b to form the augmented matrix
    augmented_matrix = [A, b];

    % Perform Gaussian elimination
    [m, n] = size(augmented_matrix);
    for i = 1:m-1
        % Partial pivoting: find the row with the maximum value in the current column
        [~, max_row] = max(abs(augmented_matrix(i:m, i)));
        max_row = max_row + i - 1;
        
        % Swap the current row with the row containing the maximum value
        if max_row != i
            augmented_matrix([i, max_row], :) = augmented_matrix([max_row, i], :);
        end
        
        % Perform row operations to eliminate elements below the pivot
        for j = i+1:m
            factor = augmented_matrix(j, i) / augmented_matrix(i, i);
            augmented_matrix(j, :) = augmented_matrix(j, :) - factor * augmented_matrix(i, :);
        end
    end

    % Back substitution to find the solution
    x = zeros(n-1, 1);
    for i = m:-1:1
        x(i) = (augmented_matrix(i, n) - augmented_matrix(i, i+1:n-1) * x(i+1:n-1)) / augmented_matrix(i, i);
    end
    
end

% Parse command-line arguments
if nargin != 2
    printf("Usage: octave 000_gaussian_elimination.m A b\n");
    printf("Example: octave gaussian_elimination.m '[2, 1, -1; -3, -1, 2; -2, 1, 2]' '[8; -11; -3]'\n");
    return;
endif

gaussian_elimination_scaled_partial_pivoting()
% Parse command-line arguments
% A = eval(argv(){1});  % Convert string input to matrix
% b = eval(argv(){2});  % Convert string input to vector


