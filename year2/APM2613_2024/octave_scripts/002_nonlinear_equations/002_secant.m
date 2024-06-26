function secant_method()
    % Convert command-line arguments to functions
    f = argv(){1};
    func = str2func(['@(x)' f]);
    x0 = str2num(argv(){2});
    x1 = str2num(argv(){3});
    tolerance = str2num(argv(){4});

    [solution,no_iterations] = secant(func, x0, x1, tolerance);
    if no_iterations > 0   % Solution found
        printf("[4] Repeat steps 2-3 until convergence, stop\n");
        printf("\tno. of iterations: %d\n",no_iterations+1);
        printf("\n");
        fprintf('A solution is: %f\n', solution)
    else
        fprintf('Abort execution.\n')
    end
end

function [solution,no_iterations] = secant(f, x0, x1, tolerance)

    printf("f:\t\t %s\n", argv(){1});
    printf("a:\t\t %s\n", argv(){2});
    printf("b:\t\t %s\n", argv(){3});
    printf("tolerance:\t\t %s\n", argv(){4});
    printf("\n");
    f_x0 = f(x0);
    f_x1 = f(x1);
    iteration_counter = 0;
    while abs(f_x1) > tolerance && iteration_counter < 100
        if iteration_counter == 0
            printf("-------------------------------------------------------- iter: %d\n",iteration_counter);
            printf("[1] Find points x_0 and x_1 such that x_0<x_1 and f(x_0)⋅f(x_1)<0\n");
        end
        try
            if iteration_counter == 0
                printf("[2] find next value x_0 using formula:\n");
            end
            denominator = (f_x1 - f_x0)/(x1 - x0);
            x = x1 - (f_x1)/denominator;
        catch
            fprintf('Error! - denominator zero for x = \n', x1)
            break
        end
        x0 = x1;
        x1 = x;
        f_x0 = f_x1;
        f_x1 = f(x1);
        if iteration_counter == 0
            printf("[3] Evaluate f(c):\n")
            printf("\tif f(x_2 )=0 then x_2 is an exact root\n")
            printf("\telse b=x_0\n")
            printf("\tand a=x_0\n")
        end
        iteration_counter = iteration_counter + 1;
    end
    % Here, either a solution is found, or too many iterations
    if abs(f_x1) > tolerance
        iteration_counter = -1;
    end
    solution = x1;
    no_iterations = iteration_counter;
end


% Parse command-line arguments
if nargin != 4
    printf("Usage: octave 002_secant.m 'x^2 - 9' 1000 999 1e-6\n");
    return;
endif

secant_method()
