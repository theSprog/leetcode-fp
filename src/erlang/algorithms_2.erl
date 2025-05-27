%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec add_two_numbers(L1 :: #list_node{} | null, L2 :: #list_node{} | null) -> #list_node{} | null.
add_two_numbers(L1, L2) ->
    F = fun(X, Y, C) ->
                Sum = X + Y + C,
                {Sum rem 10, Sum div 10}
        end,
    zip_with_list(L1, L2, 0, F).

-spec zip_with_list(L1 :: #list_node{} | null, L2 :: #list_node{} | null, Carry :: integer(),
                     F :: fun((integer(), integer(), integer()) -> {integer(), integer()})) -> #list_node{} | null.
zip_with_list(null, null, 0, _) ->
    null;
zip_with_list(L1, L2, Carry, F) ->
    A = case L1 of 
        null -> 0; 
        #list_node{val=V1} -> V1 
    end,
    B = case L2 of 
        null -> 0; 
        #list_node{val=V2} -> V2 
    end,

    {Digit, NextCarry} = F(A, B, Carry),

    Next1 = case L1 of 
        null -> null; 
        #list_node{next=N1} -> N1 
    end,
    Next2 = case L2 of 
        null -> null; 
        #list_node{next=N2} -> N2 
    end,
    
    #list_node{val=Digit, next=zip_with_list(Next1, Next2, NextCarry, F)}.


