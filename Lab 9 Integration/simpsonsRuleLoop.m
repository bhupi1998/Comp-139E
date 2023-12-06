function area = simpsonsRuleLoop(f, x0, xN, nIntervals)
% trapezoidalRule
%   area = simpsonsRuleLoop(f, x0, xN, nIntervals)
%   approximates the integral of the function f(x) between x0 and xN
%       f must be a function handle
%       nIntervals is the number of trapezoids used
%   The trapezoidal rule is a first-order method and is therefore not
%   as accurate as Simpson's rule (which is second-order)

% Check the input arguments
if ~isa(f, 'function_handle')
    error('f must be a function handle');
end

if (x0 >= xN)
    error('Invalid limits of integration.  Require x0 < xN');
end

if nIntervals < 1 || nIntervals ~= fix(nIntervals)
    error('nIntervals must be an integer greater than zero');
end

% We want N intervals, so we need N+1 points


x = linspace(x0, xN, nIntervals+1);
h = (xN - x0) / nIntervals;  % Width of one interval
sumEven = 0;
sumOdd = 0;
for index = 2:nIntervals
    if rem(index,2) == 0 %even values of index
        sumEven = f(x(index))+sumEven;
    else
        sumOdd = f(x(index))+sumOdd;
    end
end

% Add in the appropriately-weighted endpoints
% and multiply by the width of an interval
area = (f(x(1)) + f(x(end)) + 4*sumEven+2*sumOdd) * h/3;