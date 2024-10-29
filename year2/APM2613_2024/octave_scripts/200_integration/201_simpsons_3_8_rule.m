function simpsons_3_8_rule()

    % % Parse command line arguments
    % if nargin != 4
    %     printf("Usage: octave 201_simpsons_3_8_rule.m <function> <a> <b> <h>\n");
    %     printf("Example: octave 201_simpsons_3_8_rule.m '3^x' 1 1.75 0.25\n");
    %     return;
    % end

    % Convert input arguments
    function_str = argv(){1};  % Function as a string
    a = str2num(argv(){2});     % Lower limit of integration
    b = str2num(argv(){3});     % Upper limit of integration
    h = str2num(argv(){4});     % Step size

    % Create a function handle from the string
    f = @(x) eval(function_str);

    % Calculate the number of subdivisions
    n = (b - a) / h;  % Number of subdivisions
    % if mod(n, 3) != 0
    %     error('The number of subdivisions must be a multiple of 3 for Simpson\'s 3/8 Rule.');
    % end
    n = round(n);  % Ensure n is an integer

    % Define the points
    x_values = a:h:b;  % Generate points from a to b with step size h
    printf("[1] Define the Points:\n");
    for i = 1:length(x_values)
        printf("x_%d = %.4f\n", i-1, x_values(i));  % Debug output for each x_i
    end
    printf("\n");

    % Initialize the area & total
    area = 0;
    total = 0;

    % Apply Simpson's 3/8 Rule
    printf("[2] Applying Simpson's 3/8 Rule:\n");
    for i = 1:3:n-2  % Step by 3
        f_x1 = f(x_values(i));      % f(x_i)
        f_x2 = f(x_values(i+1));    % f(x_{i+1})
        f_x3 = f(x_values(i+2));    % f(x_{i+2})
        f_x4 = f(x_values(i+3));    % f(x_{i+3})

        % Multiply f(x1) and f(x2) by 3
        contribution = (3 * h / 8) * (f_x1 + 3 * f_x2 + 3 * f_x3 + f_x4);
        
        % Debug output for contributions
        printf("f(%.2f) = %.4f\n", x_values(i), f_x1);
        printf("3 × f(%.2f) = 3 × %.4f = %.4f\n", x_values(i+1), f_x2, 3 * f_x2);
        printf("3 × f(%.2f) = 3 × %.4f = %.4f\n", x_values(i+2), f_x3, 3 * f_x3);
        printf("f(%.2f) = %.4f\n", x_values(i+3), f_x4);
        
        % Sum all terms for the current interval
        total = f_x1 + (3 * f_x2) + (3 * f_x3) + f_x4;
        printf("\n[3] Sum all terms: %.4f + %.4f + %.4f + %.4f = %.4f\n", ...
               f_x1, 3 * f_x2, 3 * f_x3, f_x4, total);
        
        area += contribution;  % Add contribution to the area
    end

    % Final calculation
    area = area;  % No need to multiply by h here, as we use it in contribution
    printf("\n[4] Complete the expression:\n");
    fprintf("I ≈ (3 × %.2f) / 8 × %.4f\n", h, total);


    % Display the result
    fprintf('\n[5]Approximate integral I ≈ %.4f\n', ((3 * h)/ 8) * total);
end

% % Uncomment the following line if you want to execute the method directly
simpsons_3_8_rule()
