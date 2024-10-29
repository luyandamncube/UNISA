function newtons_divided_difference_x_values()

    % % Parse command line arguments
    % if nargin != 3
    %     printf("Usage: octave 104_newtons_divided_difference_x_values.m <partition> <function> <x_value>\n");
    %     printf("Example: octave 104_newtons_divided_difference_x_values.m '[0, 0.05, 0.1]' 'exp(2 * x)' 0.07\n");
    %     return;
    % end

    % Convert input arguments
    partition = eval(argv(){1});  % Partition points
    function_str = argv(){2};      % Function as a string
    x_eval = str2num(argv(){3});   % Value at which to evaluate the polynomial

    % Evaluate the function at the given partition points
    f = @(x) eval(function_str);  % Create a function handle from the string
    n = length(partition);
    y = zeros(n, 1);

    printf("Evaluating the function at the given partition points:\n");
    for i = 1:n
        y(i) = f(partition(i));  % Compute f(x) for each x in the partition
        printf("f(%.2f) = %.4f\n", partition(i), y(i));  % Debug output for function evaluation
    end
    printf("\n");

    % Initialize divided difference table
    div_diff = zeros(n, n);
    div_diff(:, 1) = y;  % First column is y values

    % Compute divided differences
    printf("Computing divided differences:\n");
    for j = 2:n
        for i = 1:n-j+1
            div_diff(i, j) = (div_diff(i+1, j-1) - div_diff(i, j-1)) / (partition(i+j-1) - partition(i));
            
            % Debug output showing how the divided difference was derived
            fprintf("div_diff[%d, %d] = (div_diff[%d, %d] - div_diff[%d, %d]) / (%.4f - %.4f)\n", ...
                    i, j, i+1, j-1, i, j-1, partition(i+j-1), partition(i));
            fprintf("= (%.4f - %.4f) / (%.4f - %.4f) = %.4f\n", ...
                    div_diff(i+1, j-1), div_diff(i, j-1), partition(i+j-1), partition(i), div_diff(i, j));
        end
        printf("Divided differences for j = %d: ", j);
        disp(div_diff(1:n-j+1, j));  % Display current column of divided differences
    end
    printf("\n");

    % Display the complete divided difference table
    printf("Divided Difference Table:\n");
    disp(div_diff);

    % Constructing the Newton polynomial (numerically)
    P = @(x) div_diff(1, 1);  % Initialize the polynomial with the first term
    terms = {num2str(div_diff(1, 1))};  % To store terms for final output

    printf("Constructing the Newton polynomial:\n");
    for j = 2:n
        term = div_diff(1, j);
        % Create a new function handle for the polynomial
        P_old = P;  % Save the old polynomial
        % Create the term string for debugging
        term_str = sprintf("%.4f * ", term);
        for i = 1:j-1
            term_str = [term_str sprintf("(x - %.4f) ", partition(i))];
        end
        P = @(x) P_old(x) + term * prod(x - partition(1:j-1));  % Update polynomial

        % Debug output for the current polynomial term
        fprintf("Adding term for j = %d: %s\n", j, term_str);
        terms{end+1} = term;  % Store the term for the final polynomial output
    end

    % Evaluate the polynomial at the specified x value
    interpolated_value = P(x_eval);
    
    % Print the final evaluation format
    fprintf('Evaluating P(%.2f): P(%.2f) ≈ ', x_eval, x_eval);
    fprintf('%s', num2str(terms{1}));  % Print the first term
    for j = 2:length(terms)
        fprintf(' + %.4f', terms{j});  % Print subsequent terms
    end
    fprintf(' = %.4f\n', interpolated_value);
end

% % Uncomment the following line if you want to execute the method directly
newtons_divided_difference_x_values()
