function least_squares_double_exponential()

    % % Check if the correct number of arguments is provided
    % if nargin < 3 || nargin > 7
    %     printf("Usage: octave 108_least_squares_double_exponential.m <x_values> <f_values> <x_eval> [<a0>] [<a1>] [<a2>] [<a3>]\n");
    %     printf("Example: octave 108_least_squares_double_exponential.m '[0, 1, 2, 3, 4, 5]' '[2.1, 7.7, 13.6, 27.2, 40.9, 61.1]' 2.5 2.4786 0.5 1.8607 0.1\n");
    %     return;
    % end

    % Get command-line arguments
    args = argv();

    % Count of arguments
    arg_count = numel(args);

    % Display argument count
    fprintf("Number of arguments: %d\n", arg_count);

    % Display each argument
    for i = 1:arg_count
    fprintf("Argument %d: %s\n", i, args{i});
    end

    % Parse input arguments
    x = eval(argv(){1});        % x values as an array
    y = eval(argv(){2});        % f(x) values as an array
    x_eval = str2num(argv(){3}); % Point at which to evaluate

    % Initialize a0, a1, a2, and a3
    if arg_count >= 5
        a0 = str2num(argv(){4});  % Initial guess for a0
        a1 = str2num(argv(){5});  % Initial guess for a1
        if arg_count >= 6
            a2 = str2num(argv(){6});  % Initial guess for a2
            if arg_count == 7
                a3 = str2num(argv(){7});  % Initial guess for a3
            else
                a3 = 0;  % Default value for a3 if not provided
            end
        else
            a2 = 0;  % Default value for a2 if not provided
            a3 = 0;  % Default value for a3 if not provided
        end
        use_initial_guesses = true;  % Flag to indicate use of initial guesses
    else
        use_initial_guesses = false;  % No initial guesses provided
    end

    % Check that x and y have the same length
    if length(x) != length(y)
        error('x and f(x) must have the same number of elements.');
    end

    % Prepare data for least squares fitting
    n = length(x);
    % Construct the matrix for the double exponential model
    X = [ones(n, 1), exp(a1 * x'), exp(a2 * x'), exp(a3 * x')];  % Model terms

    % Calculate coefficients using the least squares method
    coeffs = (X' * X) \ (X' * y');  % Normal equation

    % Determine whether to use initial guesses or fitted values
    if use_initial_guesses
        fitted_a0 = a0;  % Use the provided initial guess for a0
        fitted_a1 = a1;  % Use the provided initial guess for a1 
        fitted_a2 = a2;  % Use the provided initial guess for a2 
        fitted_a3 = a3;  % Use the provided initial guess for a3 
    else
        fitted_a0 = coeffs(1);  % Fitted a0
        fitted_a1 = coeffs(2);  % Fitted a1
        fitted_a2 = coeffs(3);  % Fitted a2
        fitted_a3 = coeffs(4);  % Fitted a3
    end

    % Display results
    printf('\nUsing parameters:\n');
    printf('a0 = %.4f\n', fitted_a0);
    printf('a1 = %.4f\n', fitted_a1);
    printf('a2 = %.4f\n', fitted_a2);
    printf('a3 = %.4f\n', fitted_a3);

    % Calculate approximation at x_eval
    printf("\n[1] Substitute x=%.2f to Approximate f(%.2f)\n", x_eval, x_eval);
    approx_value = fitted_a0 * exp(fitted_a1 * x_eval) + fitted_a2 * exp(fitted_a3 * x_eval);
    printf("f(%.2f) = %.4f * e^(%.4f * %.2f) + %.4f * e^(%.4f * %.2f)\n", ...
           x_eval, fitted_a0, fitted_a1, x_eval, fitted_a2, fitted_a3, x_eval);
    
    % Compute the approximation
    printf("\n[2] Compute approximation:\n");
    printf("f(%.2f) ≈ %.4f\n", x_eval, approx_value);

    % Compute error against the actual value (if within the range)
    if ismember(x_eval, x)
        actual_value = interp1(x, y, x_eval);  % Linear interpolation for actual value
        error = abs(approx_value - actual_value);
        printf("\n[3] Compute Error:\n");
        printf("Error = |%.4f − %.4f| = |%.4f|\n", approx_value, actual_value, error);
    else
        printf('Warning: x_eval = %.2f is not in the range of x values.\n', x_eval);
    end
end

function coeffs = least_squares_approximation(data_points, degree)
    % Prepare matrices for the normal equations
    X = ones(size(data_points, 1), degree + 1);
    for d = 1:degree
        X(:, d + 1) = data_points(:, 1).^d;  % Power terms
    end

    % Extract log(y) values
    y = data_points(:, 2);

    % Calculate coefficients using the least squares method
    coeffs = (X' * X) \ (X' * y);  % Normal equation
end

% Uncomment the following line if you want to execute the method directly
least_squares_double_exponential()
