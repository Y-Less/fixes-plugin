DEFINE_FIX(GetPlayerColor,
	.problem (R"(Returns "0" if "SetPlayerColor" has never been called.)")
	.solution(R"(Call "SetPlayerColor" in "OnPlayerConnect".)")
	.see     (R"("OnPlayerConnect".)")
	.author  (R"("KoczkaHUN")")
);

