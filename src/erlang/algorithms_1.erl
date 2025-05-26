-module(two_sum).
-export([two_sum/2]).

-spec two_sum(Nums :: [integer()], Target :: integer()) -> [integer()].
two_sum(Nums, Target) ->
    IndexNum = lists:zip(lists:seq(0, length(Nums)-1), Nums),

    Pairs = [{I, J} || 
            {I, X} <- IndexNum , 
            {J, Y} <- IndexNum ,  
            I < J , 
            X + Y =:= Target],

    case Pairs of
        [{I, J} | _] -> [I, J];
        [] -> {}
    end
  .