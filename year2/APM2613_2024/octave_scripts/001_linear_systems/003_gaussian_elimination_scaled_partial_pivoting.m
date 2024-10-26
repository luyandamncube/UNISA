function gaussian_elimination_scaled_partial_pivoting()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 003_gaussian_elimination_scaled_partial_pivoting.m <augmented_matrix>\n");
    %     printf("Example: octave 003_gaussian_elimination_scaled_partial_pivoting.m '[1 2 -1 3; 2 3 3 15; 3 2 1 10]'\n");
    %     return;
    % end

    % Convert input argument to numerical matrix
    A = eval(argv(){1});  % Augmented matrix

    [rows, cols] = size(A);
    n = rows;

    printf("Augmented Matrix:\n");
    disp(A);
    printf("\n");

    % Forward elimination with scaled partial pivoting
    for i = 1:n-1
        % Compute scaling factors
        scale = max(abs(A(i:n, 1:n)), [], 2);
        scale(scale == 0) = 1;  % Prevent division by zero

        % Find the pivot row based on the scaled values
        [~, pivot_index] = max(abs(A(i:n, i)) ./ scale(i:n));
        pivot_index = pivot_index + i - 1;  % Adjust index

        if pivot_index != i
            % Swap rows
            A([i, pivot_index], :) = A([pivot_index, i], :);
            printf("Swapped row %d with row %d for pivoting.\n", i, pivot_index);
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
    fprintf('Final solution:\n');
    disp(x);
end

% % Uncomment the following line if you want to execute the method directly
gaussian_elimination_scaled_partial_pivoting()
