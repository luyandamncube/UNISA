function interpolate_data()

    % % Parse command line arguments
    % if nargin != 1
    %     printf("Usage: octave 103_newtons_divided_difference.m <data_points>\n");
    %     printf("Example: octave 103_newtons_divided_difference.m '[1.435 4.35; 2.235 2.97; 3.035 2.2]'\n");
    %     return;
    % end

    % Convert input argument to numerical matrix
    data_points = eval(argv(){1});  % Data points [x, f(x)]

    % Check data dimensions
    if size(data_points, 2) != 2
        error('Data points must have two columns: [x, f(x)]');
    end

    % Extract x and f(x)
    x = data_points(:, 1);
    fx = data_points(:, 2);

    % Example for Lagrange interpolation
    % Lagrange interpolation polynomial
    p = lagrange_interpolation(x, fx, 2.5);
    fprintf('Approximation of f(2.5) using Lagrange interpolation: %.4f\n', p);

    % Example for Newton's divided difference interpolation
    result = newtons_divided_difference(data_points);
    fprintf('Approximation of f(2.5) using Newton\'s divided difference: %.4f\n', result);
end

function p = lagrange_interpolation(x, fx, x_eval)
    n = length(x);
    p = 0;

    for i = 1:n
        % Calculate the Lagrange basis polynomial
        L = 1;
        for j = 1:n
            if j != i
                L = L * (x_eval - x(j)) / (x(i) - x(j));
            end
        end
        p = p + fx(i) * L;  % Add the term to the polynomial
    end
end

function result = newtons_divided_difference(data_points)
    % Use the previous implementation or modify for this
    n = size(data_points, 1);
    x = data_points(:, 1);  
    fx = data_points(:, 2);  

    % Initialize divided difference table
    div_diff = zeros(n, n);
    div_diff(:, 1) = fx;  

    % Compute divided differences
    for j = 2:n
        for i = 1:n-j+1
            div_diff(i, j) = (div_diff(i+1, j-1) - div_diff(i, j-1)) / (x(i+j-1) - x(i));
        end
    end

    % Construct the Newton polynomial
    syms X;
    P = div_diff(1, 1);

    for j = 2:n
        term = div_diff(1, j);
        for i = 1:j-1
            term = term * (X - x(i));
        end
        P = P + term;
    end

    % Evaluate at x = 2.5
    result = double(subs(P, X, 2.5));
end

% % Uncomment the following line if you want to execute the method directly
interpolate_data()
