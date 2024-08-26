function [x] = gaussEliminationNoPivot(A, b)
    printf("A:\t %s\n", argv(){1});
    printf("b:\t %s\n", argv(){2});
    printf("\n");

    [n, ~] = size(A);
    
    % Augmented matrix
    augMat = [A b];

    disp('Initial augmented matrix:');
    disp(augMat);
    printf("\n");
    
    % Forward Elimination
    printf("Forward Elimination\n");
    for i = 1:n-1
        printf("-------------------------------------------------------- iter: %d\n",i);
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
    printf("Usage: octave 000_gaussian_elimination_no_pivot.m A b\n");
    printf("Example: octave 000_gaussian_elimination_no_pivot.m '[2 1 -1; -3 -1 2; -2 1 2]' '[8 -11 -3]'\n");
    return;
endif

A = str2num(argv(){1});
b = str2num(argv(){2});

% Reshape b into a column vector
b = b';

x = gaussEliminationNoPivot(A, b);
disp(x);