function least_squares_exponential()

    % % Check if the correct number of arguments is provided
    % if nargin < 3 || nargin > 5
    %     printf("Usage: octave least_squares_exponential.m <x_values> <f_values> <x_eval> [<a0>] [<a1>]\n");
    %     printf("Example: octave least_squares_exponential.m '[0, 1, 2, 3, 4, 5]' '[2.1, 7.7, 13.6, 27.2, 40.9, 61.1]' 2.5 2.4786 2.3593\n");
    %     return;
    % end

    % Parse input arguments
    x = eval(argv(){1});        % x values as an array
    y = eval(argv(){2});        % f(x) values as an array
    x_eval = str2num(argv(){3}); % Point at which to evaluate

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

    % Initialize a0 and a1
    if arg_count >= 5
        a0 = str2num(argv(){4});  % Initial guess for a0
        a1 = str2num(argv(){5});  % Initial guess for a1
        use_initial_guesses = true;  % Flag to indicate use of initial guesses
    else
        use_initial_guesses = false;  % No initial guesses provided
    end

    % Check that x and y have the same length
    if length(x) != length(y)
        error('x and f(x) must have the same number of elements.');
    end

    % Transform y values to logarithmic scale
    log_y = log(y);

    % Prepare data for least squares fitting
    data_points = [x', log_y'];  % Combine into a matrix [x, log(y)]

    % Fit the linear model using least squares
    coeffs = least_squares_approximation(data_points, 1);  % Fit linear model to log(y)

    % Extract fitted coefficients
    fitted_a1 = coeffs(2);
    
    % Determine whether to use initial guesses or fitted values
    if use_initial_guesses
        fitted_a0 = a0;  % Use the provided initial guess for a0
        fitted_a1 = a1;  % Use the provided initial guess for a1 
    else
        fitted_a0 = exp(coeffs(1));  % Convert back to a0
    end

    % Display results
    printf('Using parameters:\n');
    printf('a0 = %.4f\n', fitted_a0);
    printf('a1 = %.4f\n', fitted_a1);

    % Calculate approximation at x_eval
    printf("\n[1] Substitute x=%.2f to Approximate f(%.2f)\n", x_eval, x_eval);
    printf("fe^(%.2f) = %.4f ⋅ e^(%.4f ⋅ %.2f)\n", x_eval, fitted_a0, fitted_a1, x_eval);
    
    % Calculate e^(a1 * x_eval)
    exp_value = exp(fitted_a1 * x_eval);
    printf("\n[2] Find e^(%.4f ⋅ %.2f)\n", fitted_a1, x_eval);
    printf("e^(%.4f ⋅ %.2f) ≈ %.4f\n", fitted_a1, x_eval, exp_value);

    % Multiply by a0
    approx_value = fitted_a0 * exp_value;
    printf("\n[3] Multiply by a0:\n");
    printf("fe^(%.2f) ≈ %.4f ⋅ %.4f ≈ %.4f\n", x_eval, fitted_a0, exp_value, approx_value);

    % Compute the approximation
    printf("\n[4] Compute approximation:\n");
    printf("f(%.2f) ≈ %.4f\n", x_eval, approx_value);

    % Compute error against the actual value (if within the range)
    if ismember(x_eval, x)
        actual_value = interp1(x, y, x_eval);  % Linear interpolation for actual value
        error = abs(approx_value - actual_value);
        printf("\n[5] Compute Error:\n");
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

% % Uncomment the following line if you want to execute the method directly
least_squares_exponential()
