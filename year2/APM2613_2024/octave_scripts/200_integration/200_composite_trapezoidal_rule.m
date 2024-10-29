function composite_trapezoidal_rule()

    % % Parse command line arguments
    % if nargin != 4
    %     printf("Usage: octave 200_composite_trapezoidal_rule.m <function> <a> <b> <h>\n");
    %     printf("Example: octave 200_composite_trapezoidal_rule.m '3^x' 1 1.75 0.25\n");
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
    if mod(n, 1) != 0
        error('The step size h does not fit evenly into the interval [a, b].');
    end
    n = round(n);  % Ensure n is an integer

    % Define the points
    x_values = a:h:b;  % Generate points from a to b with step size h
    printf("[1] Define the Points:\n");
    for i = 1:length(x_values)
        printf("x_%d = %.4f\n", i-1, x_values(i));  % Debug output for each x_i
    end
    printf("\n");

    % Initialize the area
    area = 0.5 * (f(a) + f(b));  % Start with the first and last terms

    printf("[2] Evaluating function at each point and calculating area:\n");
    for i = 1:length(x_values)
        % printf("x_%d = %.4f\n", i-1, x_values(i));  % Debug output for each x_i
        printf("f(%.4f) = %.4f\n", x_values(i), f(x_values(i)));  % Evaluate at the lower limit

    end
    printf("\n");


    printf("\n[3] Apply the Composite Trapezoidal Rule:\n");
    printf("Formula: ∫_{%.2f}^{%.2f} %s dx ≈ (%.2f/2) (", a, b, function_str, h);

    % Calculate the area using the trapezoidal rule
    for i = 1:n-1
        x = a + i * h;  % Calculate the x value at the current subdivision
        fx = f(x);      % Evaluate the function at this x
        area = area + fx;  % Add the function value at this x to the area
        
        % Debug output for current evaluation
        printf("f(%.2f) = %.4f, Area Contribution = %.4f\n", x, fx, fx * h);
    end

    area = area * h;  % Multiply by the width to get the final area

    % Display the result
    % printf("[4] Apply the Composite Trapezoidal Rule:\n");
    fprintf('\n[4] Approximate integral I ≈ %.4f\n', area);
end

% % Uncomment the following line if you want to execute the method directly
composite_trapezoidal_rule()
