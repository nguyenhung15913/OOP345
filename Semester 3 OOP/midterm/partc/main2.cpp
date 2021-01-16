template<typename T, typename N>
class QueueItem {
	T complain_type;
	T customer_id;
public:
	QueueItem() { }
	QueueItem(const T& aa, const T& bb)
	{
		complain_type = aa;
		customer_id = bb;
	}
	const T& key() const { return complain_type; }
	const T& value() const { return customer_id; }
	void display(std::ostream& os) const
	{
		os << complain_type << ": " << customer_id << std::endl;
	}
};

template<>
QueueItem<char&, char&>(QueueItem<char&, char&>::char& value, QueueItem<char&, char&>:QueueItem::char& bb)
{
	complain_type = aa;
	customer_id = bb;
}
