<h2><a href="https://leetcode.com/problems/closest-dessert-cost/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>ByteDance</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>tiktok</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1774. Closest Dessert Cost</a></h2><h3>Medium</h3><hr><div><p>You would like to make dessert and are preparing to buy the ingredients. You have <code>n</code> ice cream base flavors and <code>m</code> types of toppings to choose from. You must follow these rules when making your dessert:</p>

<ul>
	<li>There must be <strong>exactly one</strong> ice cream base.</li>
	<li>You can add <strong>one or more</strong> types of topping or have no toppings at all.</li>
	<li>There are <strong>at most two</strong> of <strong>each type</strong> of topping.</li>
</ul>

<p>You are given three inputs:</p>

<ul>
	<li><code>baseCosts</code>, an integer array of length <code>n</code>, where each <code>baseCosts[i]</code> represents the price of the <code>i<sup>th</sup></code> ice cream base flavor.</li>
	<li><code>toppingCosts</code>, an integer array of length <code>m</code>, where each <code>toppingCosts[i]</code> is the price of <strong>one</strong> of the <code>i<sup>th</sup></code> topping.</li>
	<li><code>target</code>, an integer representing your target price for dessert.</li>
</ul>

<p>You want to make a dessert with a total cost as close to <code>target</code> as possible.</p>

<p>Return <em>the closest possible cost of the dessert to </em><code>target</code>. If there are multiple, return <em>the <strong>lower</strong> one.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> baseCosts = [1,7], toppingCosts = [3,4], target = 10
<strong>Output:</strong> 10
<strong>Explanation:</strong> Consider the following combination (all 0-indexed):
- Choose base 1: cost 7
- Take 1 of topping 0: cost 1 x 3 = 3
- Take 0 of topping 1: cost 0 x 4 = 0
Total: 7 + 3 + 0 = 10.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
<strong>Output:</strong> 17
<strong>Explanation:</strong> Consider the following combination (all 0-indexed):
- Choose base 1: cost 3
- Take 1 of topping 0: cost 1 x 4 = 4
- Take 2 of topping 1: cost 2 x 5 = 10
- Take 0 of topping 2: cost 0 x 100 = 0
Total: 3 + 4 + 10 + 0 = 17. You cannot make a dessert with a total cost of 18.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> baseCosts = [3,10], toppingCosts = [2,5], target = 9
<strong>Output:</strong> 8
<strong>Explanation:</strong> It is possible to make desserts with cost 8 and 10. Return 8 as it is the lower cost.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == baseCosts.length</code></li>
	<li><code>m == toppingCosts.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10</code></li>
	<li><code>1 &lt;= baseCosts[i], toppingCosts[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>
</div>