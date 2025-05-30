function gaussian_elimination()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 000_gaussian_elimination.m <augmented_matrix>\n");
    %     printf("Example: octave 000_gaussian_elimination.m '[1 2 -1 3; 2 3 3 15; 3 2 1 10]'\n");

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

    % Forward elimination
    for i = 1:n-1
        printf("--------------------------------------------------------\n");
        printf("Eliminating variable x%d:\n", i);
        
        % Partial pivoting
        [~, max_index] = max(abs(A(i:n, i)));
        max_index = max_index + i - 1;  % Adjust index
        if max_index != i
            % Swap rows
            A([i, max_index], :) = A([max_index, i], :);
            printf("Swapped row %d with row %d for pivoting.\n", i, max_index);
            disp(A);
        end

        % Elimination process
        for j = i+1:n
            factor = A(j, i) / A(i, i);
            A(j, :) = A(j, :) - factor * A(i, :);
            printf("Row %d updated using factor %f:\n", j, factor);
            disp(A);
        end
        printf("\n");
    end

    % Back substitution
    x = zeros(n, 1);  % Solution vector
    printf("--------------------------------------------------------\n");
    printf("Back substitution:\n");
    
    for i = n:-1:1
        x(i) = (A(i, end) - A(i, 1:end-1) * x) / A(i, i);
        printf("Solving for x%d: %f\n", i, x(i));
    end

    % Final output
    fprintf('Solution:\n');
    disp(x);
end

% % Uncomment the following line if you want to execute the method directly
gaussian_elimination()


% '[2, 1, -1; -3, -1, 2; -2, 1, 2]' '[8; -11; -3]'
% [1 2 -1 3; 2 3 3 15; 3 2 1 10]