function lagrange_interpolation()

    % % Check if the correct number of arguments is provided
    % if nargin < 2
    %     printf("Usage: octave 110_lagrange_interpolation.m <x_values> <f_values> <x_eval>\n");
    %     printf("Example: octave 110_lagrange_interpolation.m '[0, 1, 2, 3]' '[1, 2, 0, 5]' 1.5\n");
    %     return;
    % end

    % Parse input arguments
    x = eval(argv(){1});        % x values as an array
    y = eval(argv(){2});        % f(x) values as an array
    x_eval = str2num(argv(){3}); % Point at which to evaluate

    % Check that x and y have the same length
    if length(x) != length(y)
        error('x and f(x) must have the same number of elements.');
    end

    n = length(x);  % Number of data points
    interpolated_value = 0;  % Initialize the result

    % Calculate the Lagrange polynomial
    printf("Calculating Lagrange interpolation for f(%.2f):\n", x_eval);
    for i = 1:n
        % Calculate the Lagrange basis polynomial L_i
        L_i = 1;
        for j = 1:n
            if i != j
                L_i *= (x_eval - x(j)) / (x(i) - x(j));
            end
        end

        % Update the interpolated value
        interpolated_value += y(i) * L_i;

        % Debugging output for each term
        printf("L_%d(%.2f) = %.4f\n", i, x_eval, L_i);
    end

    % Display the final interpolated value
    printf("Interpolated value at f(%.2f) ≈ %.4f\n", x_eval, interpolated_value);
end

% Uncomment the following line if you want to execute the method directly
lagrange_interpolation()
