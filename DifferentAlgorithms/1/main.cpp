Object obj1;
Object obj2;

if (obj1 > obj2)
return obj2;

template<class T>
T& Compare(const T& obj1, const T& obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}

try
{
	throw 1;
}
catch (...)
{

}


Loop()
{
	while (true)
	{
		out << "First player enter: \n";
		cin >> i >> j >> x;

		Game::CheckTern();

		cout << "Second player enter: \n";
		cin >> i >> j >> x;

		Game::CheckTern();

		Status status = Geme::CheckGameStatus();


		if (status = GameFinished)
		{
			return Status::winer;
			break;
		}

	}
}