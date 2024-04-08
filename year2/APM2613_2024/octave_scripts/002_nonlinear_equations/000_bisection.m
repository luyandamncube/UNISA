function root = bisection_method(f, a, b, tol, max_iter)
    % f: function handle representing the function
    % a, b: initial interval [a, b]
    % tol: tolerance (stopping criterion)
    % max_iter: maximum number of iterations
    
    printf("f:\t\t %s\n", argv(){1});
    printf("a:\t\t %s\n", argv(){2});
    printf("b:\t\t %s\n", argv(){3});
    printf("tol:\t\t %s\n", argv(){4});
    printf("max_iter:\t %s\n", argv(){5});
    printf("\n");
    % Check if the function changes sign within the interval
    if f(a) * f(b) >= 0
        error('Function does not change sign within the interval');
    else
        printf("[1] Initialize the interval [a,b]\n");
        printf("\tfunction changes sign within the interval\n");
        printf("\tf(a): %d \n", f(a));
        printf("\tf(b): %d \n", f(b));
        printf("\n");
    end
    
    % Initialize iteration counter and interval width
    iter = 0;
    width = b - a;
    
    % Iterate until convergence or max_iter reached
    while width > tol && iter < max_iter
        
        % Compute midpoint of the interval
        c = (a + b) / 2;
        if iter == 0
            printf("-------------------------------------------------------- iter: %d\n",iter)
            printf("[2] Calculate the midpoint:\n");
            printf("\tc=(a+b)/2 = %d\n",c);
            printf("\n");
        end
        
        % Check if the midpoint is the root
        if abs(f(c)) < tol
            root = c;
            % width of the interval is smaller than predetermined tolerance
            % if f(c)=0 or |b-a|<tolerance, stop
            return;
        end
        
        % Update interval
        if iter == 0
            printf("[3] Evaluate f(c)\n")
        end
        if f(a) * f(c) < 0
            b = c;
            if iter == 0
                printf("\t- if f(c) has the same sign as f(a), set a=c\n");
                printf("\t- if f(c) has the same sign as f(b), set b=c\n");
                printf("\tf(c)= f(%d) = (%d)\n", c, f(c)) 
                printf("\tf(b)= f(%d) = (%d)\n", b, f(b)) 
                printf("\tf(c) has the same sign as f(b). set b=c\n");
                printf("\troot lies in the left half of the interval\n");
                printf("\n");
            end
        else
            a = c;
            if iter == 0
                printf("\t- if f(c) has the same sign as f(a), set a=c\n");
                printf("\t- if f(c) has the same sign as f(b), set b=c\n");
                printf("\n");
                printf("\tf(c)= f(%d) = (%d)\n", c, f(c)) 
                printf("\tf(a)= f(%d) = (%d)\n", a, f(a)) 
                printf("\troot lies in the right half of the interval\n");
                printf("\n");
            end
        end

        % Update interval width and iteration count
        width = b - a;
        iter = iter + 1;
        
    end
    
    % If max_iter reached without convergence, display a warning
    if iter == max_iter
        warning('Maximum number of iterations reached without convergence');
    end
    
    % Return the root found (approximation)
    printf("--------------------------------------------------------\n")
    printf("[4] Repeat steps 2-3 until convergence, stop\n");
    printf("\tno. of iterations: %d\n",iter);
    printf("\n");
    root = (a + b) / 2;
end

% Parse command line arguments
if nargin != 5
    printf("Usage: octave 000_bisection.m <function_definition> <a> <b> <tol> <max_iter>\n");
    printf("Example: octave 000_bisection.m '3*x^3 - 10*x^2 + 13/4 + 15/2' 0 2 1e-6 100\n");
    return;
end

% Convert input arguments to numerical values
f_str = argv(){1};
a = str2num(argv(){2});
b = str2num(argv(){3});
tol = str2num(argv(){4});
max_iter = str2num(argv(){5});

% Define the function f(x) using the input string
f = str2func(['@(x)' f_str]);

% Call the bisection method function to find the root
root = bisection_method(f, a, b, tol, max_iter);

% Display the root
disp(['Root found using bisection method: ', num2str(root)]);
