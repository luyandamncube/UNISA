function gaussian_elimination_no_pivoting()

    % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 003_gaussian_elimination_no_pivoting.m <augmented_matrix>\n");
    %     printf("Example: octave 003_gaussian_elimination_no_pivoting.m '[1 2 -1 3; 2 3 3 15; 3 2 1 10]'\n");
    %     return;
    % end

    % Convert input argument to numerical matrix
    A = eval(argv(){1});  % Augmented matrix

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
        x(i) = (A(i, end) - A(i, 1:end-1) * x) / A(i, i);
        printf("Solving for x%d: %f\n", i, x(i));
    end

    % Final output
    fprintf('Final solution:\n');
    disp(x);
end

% % Uncomment the following line if you want to execute the method directly
gaussian_elimination_no_pivoting()
