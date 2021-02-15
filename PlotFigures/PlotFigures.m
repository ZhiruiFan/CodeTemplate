%   Define the variables
theta = 0 : 10;

%   Calcualte the value of sin(x)
y = sin(theta);

%   Plot the x-y figures
figure(1);              % This command can be omitted
plot(theta, y, 'r--o', 'linewidth', 2);

%   Setting of the tick font of axis
set(gca, 'xcolor', 'b', 'ycolor', 'r', 'FontName', 'Courier 10 Pitch', 'FontSize', 18)

%   Some configuration of the plot
xlabel('Design variables: \theta', 'Color', 'b', 'FontName', 'Courier 10 Pitch', 'FontSize', 20)
%   Here you can change 'Courier 10 Pitch' to 'Arial', 'Times New Roman'
%   etc.
ylabel('Function y = sin(\theta)', 'color', 'r', 'FontName', 'Courier 10 Pitch', 'FontSize', 20)

%   Setting of axis
axis on
axis tight

%   Setting of background
set(1, 'color', 'w')

%   Open the grid
grid on

%   Open the box
box on