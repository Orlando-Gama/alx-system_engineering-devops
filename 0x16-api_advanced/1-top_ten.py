#!/usr/bin/python3
"""
Queries the Reddit API and prints the titles of the first 10 hot posts listed
for a given subreddit.
"""

import requests

def top_ten(subreddit):
    url = f"https://www.reddit.com/r/{subreddit}/hot.json?limit=10"
    headers = {"User-Agent": "my_bot/1.0"}  # Replace with your user agent

    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        data = response.json().get("data", {}).get("children", [])

        if data:
            for post in data:
                print(post["data"]["title"])
        else:
            print("No posts found in the subreddit.")
    else:
        print("None")

if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
        print("Please pass an argument for the subreddit to search.")
    else:
        top_ten(sys.argv[1])
