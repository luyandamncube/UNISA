function [x] = gaussEliminationScaledPartialPivoting(A, b)
    printf("A:\t %s\n", argv(){1});
    printf("b:\t %s\n", argv(){2});
    printf("\n");

    [n, ~] = size(A);
    
    % Augmented matrix
    augMat = [A b];

    disp('Initial augmented matrix:');
    disp(augMat);
    printf("\n");
    
    % Forward Elimination with Scaled Partial Pivoting
    printf("Forward Elimination with Scaled Partial Pivoting\n");
    for i = 1:n-1
        printf("-------------------------------------------------------- iter: %d\n",i);
        % Find the pivot row
        [~, pivot_row] = max(abs(augMat(i:n, i)) ./ max(abs(augMat(i:n, i:n)), [], 2));
        pivot_row = pivot_row + i - 1;
        
        % Swap rows if necessary
        if pivot_row != i
            augMat([i pivot_row], :) = augMat([pivot_row i], :);
            printf("Swapping rows %d and %d\n", i, pivot_row);
            disp(augMat);
        end
        
        for j = i+1:n
            printf("R%d: R%d - (%d/%d)*R%d\n", j, j, augMat(j,i), augMat(i,i), i);
            factor = augMat(j,i) / augMat(i,i);
            augMat(j,:) = augMat(j,:) - factor * augMat(i,:);
        end
        printf("\n");
        disp(augMat);
    end
    
    % Back Substitution
    printf("\nBack Substitution:\n");
    x = zeros(n,1);
    x(n) = augMat(n,n+1) / augMat(n,n);
    printf("x_%d: %d/%d = %d\n", n, augMat(n,n+1), augMat(n,n), x(n));

    for i = n-1:-1:1
        x(i) = (augMat(i,n+1) - augMat(i,i+1:n) * x(i+1:n)) / augMat(i,i);

        printf("x_%d: (%d - %d) /%d  = %d\n", i, augMat(i,n+1), augMat(i,i+1:n) * x(i+1:n),  augMat(i,i), x(i));
    end
    printf("\n");
end

% Parse command-line arguments
if nargin != 2
    printf("Usage: octave 001_gaussian_elimination_scaled_partial_pivoting.m A b\n");
    printf("Example: octave 001_gaussian_elimination_scaled_partial_pivoting.m '[2 1 -1; -3 -1 2; -2 1 2]' '[8 -11 -3]'\n");
    return;
endif

A = str2num(argv(){1});
b = str2num(argv(){2});

% Reshape b into a column vector
b = b';

x = gaussEliminationScaledPartialPivoting(A, b);
disp(x);
