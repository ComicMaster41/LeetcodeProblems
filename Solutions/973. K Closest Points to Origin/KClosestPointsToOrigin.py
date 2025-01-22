def kClosest(points, k):
    # √(x1 - x2)2 + (y1 - y2)2
    # points[i] = [xi, yi]
    # k = closest point to origin [0, 0]
    # can return answer in any order

    # Input: points = [[1,3],[-2,2]], k = 1
    # Output: [[-2,2]]
    # Explanation:
    # The distance between (1, 3) and the origin is sqrt(10).
    # The distance between (-2, 2) and the origin is sqrt(8).
    # Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    # We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

    """
    we want to find the k closest points to the origin
    first, we want to add the x and y squared coordinates, then compare the two values
    once we compare them, we can check which are the closest points
    k represents HOW MANY points we want to return

    This is an interesting one, because what we can do is we can start with the largest in the original
    list and essentially remove them until we are set

    The first thing I want to work on is making sure that I have the distances
    one brute force method is to make a list of all of the origins and the coordinates
    and map them into a dictionary maybe

    i can see this overcomplicating the issue

    so the real solution is to modify the points list by sorting the list
    by whatever k[0]^2 + k[1]^2 returns. this signifies the x and y coordinates
    then we can slice however many elements in the list we need (indicated by k)

    shortest_list = []

    for each of the points in the list
    for i in points:
        for the x and y coordinate
        for point in points:
            this holds the distance of the coordinate
            dist = sqrt(point[0]**2 + point[1]**2)
            sort the points according to the distances
            points.sort(dist)
    return points(:k)

    """

    points.sort(key = lambda k: k[0]**2 + k[1]**2)
    points = points[:k]
    print(points)
kClosest([[1,3],[-2,2]], 1)
