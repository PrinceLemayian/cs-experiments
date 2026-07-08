% Prolog logic programming example

% Facts
mammal(dog).
mammal(cat).
has_fur(dog).
has_fur(cat).

% Rule: An animal is a pet if it is a mammal and has fur
is_pet(X) :- mammal(X), has_fur(X).

% Query to be executed by the user in the console:
% ?- is_pet(dog).
% The inference engine deduces 'true'.
