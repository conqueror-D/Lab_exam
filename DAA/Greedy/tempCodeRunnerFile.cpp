
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair curr = pq.top();
        pq.pop();

        int vertex = curr.first;
        if (taken[vertex])