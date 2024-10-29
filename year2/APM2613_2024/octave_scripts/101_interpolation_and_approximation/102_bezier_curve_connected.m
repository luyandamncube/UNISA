% Define the dataset
data = [
    10, 10;
    50, 15;
    75, 60;
    90, 100;
    105, 140;
    150, 200;
    180, 140;
    190, 120;
    160, 100;
    130, 80
];

% Number of points in the dataset
n = size(data, 1);

% Prepare for plotting
figure;
hold on;

% Plot original data points
plot(data(:, 1), data(:, 2), 'ro-', 'MarkerFaceColor', 'r', 'DisplayName', 'Data Points');

% Number of points for the Bézier curve
num_points_per_segment = 100;

% Loop through each segment and plot the cubic Bézier curve
for i = 1:n-3
    % Control points for the cubic Bézier curve
    P0 = data(i, :);
    P1 = data(i + 1, :);
    P2 = data(i + 2, :);
    P3 = data(i + 3, :);

    % Preallocate for curve points
    curve_points = zeros(num_points_per_segment, 2);

    % Compute the Bézier curve points
    for j = 1:num_points_per_segment
        t = (j - 1) / (num_points_per_segment - 1); % Normalize t from 0 to 1
        curve_points(j, :) = (1-t)^3 * P0 + ...
                             3*t*(1-t)^2 * P1 + ...
                             3*t^2*(1-t) * P2 + ...
                             t^3 * P3;
    end

    % Plot the Bézier curve
    plot(curve_points(:, 1), curve_points(:, 2), 'b-', 'LineWidth', 2);
end

% Plot settings
title('Connected Bézier Polynomial from Dataset');
xlabel('x');
ylabel('y');
%legend show;
grid on;
axis equal;
hold off;
