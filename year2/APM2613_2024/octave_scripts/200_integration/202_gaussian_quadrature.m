function gaussian_quadrature()

    % % Parse command line arguments
    % if nargin != 4
    %     printf("Usage: octave 202_gaussian_quadrature.m <function> <a> <b> <n>\n");
    %     printf("Example: octave 202_gaussian_quadrature.m '3^x' 1 1.75 3\n");
    %     return;
    % end

    % Convert input arguments
    function_str = argv(){1};  % Function as a string
    a = str2num(argv(){2});     % Lower limit of integration
    b = str2num(argv(){3});     % Upper limit of integration
    n = str2num(argv(){4});     % Number of points (should be 3 for three-point quadrature)

    if n != 3
        error('This implementation is specifically for the three-point Gaussian quadrature.');
    end

    % Create a function handle from the string
    f = @(x) eval(function_str);

    % Three-point Gaussian quadrature weights and nodes
    r = [-0.774596669241483, 0.0, 0.774596669241483]; % Roots of the polynomial
    c = [0.555555555555556, 0.888888888888889, 0.555555555555556]; % Weights

    % Change of variables from [a, b] to [-1, 1]
    mid = (b + a) / 2;
    half = (b - a) / 2;

    % Debugging outputs
    printf("[1] Define a change of variable:\n");
    printf("x = (%.2f - %.2f)/2 * t + (%.2f + %.2f)/2\n", b, a, b, a);
    printf("x = %.4f * t + %.4f\n", half, mid);
    printf("\n");

    printf("[2] Differentiate:\n");
    printf("dx = (%.2f - %.2f)/2 * dt = %.4f dt\n", b, a, half);
    printf("\n");

    printf("[3] Integral setup:\n");
    printf("I = ∫_%.2f^{%.2f} %s dx = ∫_{-1}^{1} %s ⋅ %.4f dt\n", a, b, function_str, ...
           sprintf('%s', strrep(function_str, 'x', sprintf('(%.4f * t + %.4f)', half, mid))), half);
    printf("\n");

    % Initialize the integral
    integral = 0;
    contributions = zeros(1, n);  % Array to store contributions for debugging

    % Applying Gaussian Quadrature
    printf("[4] Applying Gaussian Quadrature:\n");
    for i = 1:n
        x = mid + half * r(i);  % Change of variable
        weight = c(i);
        contribution = weight * f(x);  % Accumulate the weighted function evaluations
        contributions(i) = contribution;  % Store the contribution
        printf("f(%.4f) = %.4f, Weight = %.4f, Contribution = %.4f\n", x, f(x), weight, contribution);
        integral += contribution;  % Update the integral
    end

    % Scale the result by half the width of the interval
    integral = half * integral;

    % Debugging output for result sum
    printf("\n[5] Result sum:\n");
    fprintf("I ≈ %.3f ⋅ (", half);
    fprintf("%s", num2str(contributions(1), '%.4f'));  % Print first contribution
    for i = 2:n
        fprintf(" + %.4f", contributions(i));  % Print subsequent contributions
    end
    fprintf(") = %.3f ⋅ %.4f\n", half, sum(contributions));  % Print final sum

    % Display the result
    fprintf("\n[6] Approximate integral I ≈ %.4f\n", integral);
end

% % Uncomment the following line if you want to execute the method directly
gaussian_quadrature()
