#include "PerfectPlayer.hpp"

void PlayFromNode(std::shared_ptr<Node> n, Board::Player turn)
{
	if (!n->board.movesRemain())
	{
		n->winnerFromHere = n->board.winner();
	}
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
		{
			if (n->board(i, j) == Board::EMPTY)
			{
				auto next  = n->board.move(i, j, turn);
				n->children.push_back(std::make_shared<Node>(next));
			}
		}
	auto otherTurn = turn == Board::PLAYER_X ? Board::PLAYER_O : Board::PLAYER_X;
	for (auto& child : n->children)
	{
		PlayFromNode(child, otherTurn);
	}

	n->winnerFromHere = otherTurn;
	for (auto& child : n->children)
	{
		if (child->winnerFromHere == turn)
		{
			n->winnerFromHere = turn;
		}
		else if (child->winnerFromHere == Board::EMPTY)
		{
			if (n->winnerFromHere == otherTurn)
			{
				n->winnerFromHere = Board::EMPTY;
			}
		}
	}
}


PerfectPlayer::PerfectPlayer(Board::Player player):
Player(player), plan(), cur(nullptr)
{
	auto start = std::make_shared<Node>(Board());
	PlayFromNode(start, Board::PLAYER_X);

	if (player == Board::PLAYER_X)
	{
		auto dummy = std::make_shared<Node>(Board());
		dummy->winnerFromHere = start->winnerFromHere;
		dummy->children.push_back(start);
		plan = dummy;
	}
	else
	{
		plan = start;
	}

	cur = plan.get();
}

Board PerfectPlayer::move(Board board)
{
	auto next = std::find_if(cur->children.begin(), cur->children.end(), [board](std::shared_ptr<Node> const & n) {return n->board == board; });
	
	assert(next != cur->children.end());

	std::shared_ptr<Node> best = nullptr;
	for (auto& child : (*next)->children)
	{
		if (!best)
		{
			best = child;
		}
		else
		{
			if (child->winnerFromHere == mPlayer)
			{
				best = child;
			}
			else if (child->winnerFromHere == Board::EMPTY)
			{
				if (best->winnerFromHere != mPlayer)
					best = child;
			}
		}
	}

	cur = best.get();

	return best->board; 
}

