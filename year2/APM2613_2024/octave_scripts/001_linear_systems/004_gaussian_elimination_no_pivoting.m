function gaussian_elimination_no_pivoting()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 004_gaussian_elimination_no_pivoting.m <augmented_matrix>\n");
    %     printf("Example: octave 004_gaussian_elimination_no_pivoting.m '[1 2 -1 3; 2 3 3 15; 3 2 1 10]'\n");
    %     return;
    % end
 

    input_str = argv(){1};
    clean_str = regexprep(input_str, '[\\/]', '');  % Removes all '/' and '\' characters
    % disp(clean_str);
    % Convert the cleaned string to a matrix
    A = eval(clean_str);  % Augmented matrix

    [rows, cols] = size(A);
    n = rows;

    printf("Augmented Matrix:\n");
    disp(A);
    printf("\n");

    % Forward elimination without pivoting
    for i = 1:n-1
        printf("--------------------------------------------------------\n");
        printf("Eliminating variable x%d:\n", i);
        
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
        sum = A(i, end);  % Start with the last column value

        % Build the equation string for debugging
        equation = sprintf("x%d = (%.4f ", i, sum);

        for j = i+1:n
            sum = sum - A(i, j) * x(j);  % Subtract the contributions of already solved variables
            equation = sprintf("%s- (%.4f * x%d) ", equation, A(i, j), j);
        end

        x(i) = sum / A(i, i);
        equation = sprintf("%s)/ %.4f = %.4f\n", equation, A(i, i), x(i));
        
        % Print the equation used to solve for x_i
        printf("%s", equation);
    end

    % Final output
    fprintf('Final solution:\n');
    disp(x);
end

% % Uncomment the following line if you want to execute the method directly
gaussian_elimination_no_pivoting()
