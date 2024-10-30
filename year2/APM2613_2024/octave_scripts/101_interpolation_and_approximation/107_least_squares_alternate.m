function least_squares_alternate()

    % % Check if the correct number of arguments is provided
    % if nargin < 3 || nargin > 5
    %     printf("Usage: octave 107_least_squares_alternate.m <x_values> <f_values> <x_eval> [<a0>] [<a1>] [<a2>]\n");
    %     printf("Example: octave 107_least_squares_alternate.m '[0, 1, 2, 3, 4, 5]' '[2.1, 7.7, 13.6, 27.2, 40.9, 61.1]' 2.5 2.4786 2.3593 1.8607\n");
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

    % Initialize a0, a1, and a2
    if arg_count >= 5
        a0 = str2num(argv(){4});  % Initial guess for a0
        a1 = str2num(argv(){5});  % Initial guess for a1
        if arg_count == 6
            a2 = str2num(argv(){6});  % Initial guess for a2 (optional)
        else
            a2 = 0;  % Default value for a2 if not provided
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
    X = ones(n, 3);  % Create a matrix for the polynomial terms (a0, a1, a2)
    X(:, 2) = x';     % x values (1st degree)
    X(:, 3) = x'.^2;  % x^2 values (2nd degree)

    % Calculate coefficients using the least squares method
    coeffs = (X' * X) \ (X' * y');  % Normal equation

    % Determine whether to use initial guesses or fitted values
    if use_initial_guesses
        fitted_a0 = a0;  % Use the provided initial guess for a0
        fitted_a1 = a1;  % Use the provided initial guess for a1 
        fitted_a2 = a2;  % Use the provided initial guess for a2 
    else
        fitted_a0 = coeffs(1);  % Fitted a0
        fitted_a1 = coeffs(2);  % Fitted a1
        fitted_a2 = coeffs(3);  % Fitted a2
    end

    % Display results
    printf('\nUsing parameters:\n');
    printf('a0 = %.4f\n', fitted_a0);
    printf('a1 = %.4f\n', fitted_a1);
    printf('a2 = %.4f\n', fitted_a2);

    % Calculate approximation at x_eval
    printf("\n[1] Substitute x=%.2f to Approximate f(%.2f)\n", x_eval, x_eval);
    approx_value = fitted_a0 + fitted_a1 * x_eval + fitted_a2 * x_eval^2;
    printf("f(%.2f) = %.4f + %.4f * %.2f + %.4f * (%.2f^2)\n", ...
           x_eval, fitted_a0, fitted_a1, x_eval, fitted_a2, x_eval);
    
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

% Uncomment the following line if you want to execute the method directly
least_squares_alternate()
