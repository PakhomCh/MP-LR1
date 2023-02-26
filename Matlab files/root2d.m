function F = root2d( x )

    F(1) = x(1)^2 + x(2)^2 - 1;
    F(2) = sin(x(1) + x(2)) - 0.2 - x(1);

end

