clc

disp('Expected roots: -1.3, -0.3, 0.3 and 4.1')
root1 = fzero('3 * x^4 - 8 * x^3 - 18 * x^2 + 2', [-2 -1]);
root2 = fzero('3 * x^4 - 8 * x^3 - 18 * x^2 + 2', [-1 0]);
root3 = fzero('3 * x^4 - 8 * x^3 - 18 * x^2 + 2', [0 1]);
root4 = fzero('3 * x^4 - 8 * x^3 - 18 * x^2 + 2', [4 5]);
disp('Found roots:')
disp([root1, root2, root3, root4])

disp('Expected roots: -0.1 and 0.7')
root1 = fzero('tan(0.55 * x + 0.1) - x^2', [-1 0]);
root2 = fzero('tan(0.55 * x + 0.1) - x^2', [0 1]);
disp('Found roots:')
disp([root1, root2])

disp('Expected roots: {-0.99, 0.07} or {0.78, 0.61}')
fun = @root2d;
x0 = [0, 0];
root1 = fsolve(fun, x0);
disp('Found roots:')
disp(root1)