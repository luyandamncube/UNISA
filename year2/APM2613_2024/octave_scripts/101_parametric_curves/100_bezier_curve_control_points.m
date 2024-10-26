% Define control points
P0 = [0, 0];   % P0
P1 = [1, 2];   % P1
P2 = [2, 2];   % P2
P3 = [3, 0];   % P3

% Number of points for the curve
num_points = 100;
t_values = linspace(0, 1, num_points);
curve_points = zeros(num_points, 2); % Preallocate matrix for curve points

% Compute the Bézier curve points
for i = 1:num_points
    t = t_values(i);
    curve_points(i, :) = (1-t)^3 * P0 + 3*t*(1-t)^2 * P1 + ...
                         3*t^2*(1-t) * P2 + t^3 * P3;
end

% Plotting the curve and control points
figure;
plot(curve_points(:, 1), curve_points(:, 2), 'b-', 'LineWidth', 2); % Bézier curve
hold on;
plot([P0(1), P1(1), P2(1), P3(1)], [P0(2), P1(2), P2(2), P3(2)], 'ro--', 'MarkerFaceColor', 'r'); % Control Points
text(P0(1), P0(2), 'P0', 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');
text(P1(1), P1(2), 'P1', 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');
text(P2(1), P2(2), 'P2', 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');
text(P3(1), P3(2), 'P3', 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');
title('Cubic Bézier Curve');
xlabel('x');
ylabel('y');
axis equal;
grid on;
hold off;