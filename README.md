# ResearchProjects
My sample research papers in algorithms and optimization for wireless sensor networks and smart grid (EV scheduling)

• B. Alinia, M. H. Hajiesmaili and, N. Crespi, “Online Charging Scheduling of EVs with On-Arrival Charging Commitments,” IEEE Transactions
on Intelligent Transportation Systems, 2019.

Abstract—The rapid proliferation of electric vehicles has
resulted in a drastic increase in the total energy demand of EVs.
Given the limited charging rate capacity of charging stations
and uncertainty of EV arrivals, the aggregate demand might go
beyond the charging station capacity, even with proper scheduling.
This paper formulates a social welfare maximization problem
for EV charging scheduling with charging capacity constraint.
Even though the underlying problem is linear, it is difficult to
tackle since the input to the problem, i.e., the charging profile
of EVs, reveals in online fashion. We devise charging scheduling
algorithms that not only work in the online scenario, but also
provide the following two key features: 1) on-arrival commitment;
respecting the capacity constraint may hinder fulfilling charging
requirement of the deadline-constrained EVs entirely. Therefore,
committing a guaranteed charging amount upon arrival of each
EV is highly essential; 2) (group)-strategy-proofness as a salient
feature to promote EVs to reveal their true type and do not
collude with other EVs. Extensive simulations using real traces
demonstrate the effectiveness of our online scheduling algorithms
as compared to the optimal non-committed offline solution.

##########################################################################################
• B. Alinia, M. H. Hajiesmaili, M. S. Talebi, and N. Crespi, “Competitive Online Scheduling Algorithms with Applications in Deadline-
Constrained EV Charging,” in Proc. of IEEE/ACM International Symposium on Quality of Service (IWQoS), 2018.
acceptance ratio: 20.8%

Abstract—This paper studies the classical problem of online
scheduling of deadline-sensitive jobs with partial values and
investigates its extension to Electric Vehicle (EV) charging
scheduling by taking into account the processing rate limit of
jobs and charging station capacity constraint. The problem lies in
the category of time-coupled online scheduling problems without
availability of future information. This paper proposes two online
algorithms, both of which are shown to be (2-1/U)-competitive,
where U is the maximum scarcity level, a parameter that
indicates demand-to-supply ratio. The first proposed algorithm
is deterministic, whereas the second is randomized and enjoys
a lower computational complexity. When U grows large, the
performance of both algorithms approaches that of the stateof-
the-art for the case where there is processing rate limits on
the jobs. Nonetheless in realistic cases, where U is typically small,
the proposed algorithms enjoy a much lower competitive ratio. To
carry out the competitive analysis of our algorithms, we present a
proof technique, which is novel to the best of our knowledge. This
technique could also be used to simplify the competitive analysis
of some existing algorithms, and thus could be of independent
interest.

##########################################################################################
• B. Alinia, M. H. Hajiesmaili, A. Khonsari and, N. Crespi,“Maximum-Quality Tree Construction for Deadline-Constrained Aggregation in WSNs,” IEEE Sensors Journal, 2017.

Abstract—In deadline-constrained wireless sensor networks
(WSNs), the quality of aggregation (QOA) is determined
by the number of participating nodes in the data aggregation
process. The previous studies have attempted to propose optimal
scheduling algorithms to obtain the maximum QOA assuming a
fixed underlying aggregation tree. However, there exists no prior
work to address the issue of constructing optimal aggregation
tree in deadline-constraints WSNs. The structure of underlying
aggregation tree is important since our analysis demonstrates
that the ratio between the maximum achievable QOAs of
different trees could be as large as O(2^D), where D is the
deadline. This paper casts a combinatorial optimization problem
to address the optimal tree construction for deadline-constrained
data aggregation in WSNs. While the problem is proved to be
NP-hard, we employ the Markov approximation framework and
devise two distributed algorithms with different computation
overheads to find close-to-optimal solution with bounded
approximation gap. To further improve the convergence of
the Markov-based algorithms, we devise another initial tree
construction algorithm with low-computational complexity. Our
experimental results from a set of randomly-generated scenarios
demonstrate that the proposed algorithms achieve near optimal
performance and appreciably outperform methods that work
on a fixed aggregation tree by obtaining better quality of
aggregation.

##########################################################################################
• B. Alinia, M. H. Hajiesmaili, and A. Khonsari, “On the Construction of Maximum-Quality Aggregation Trees in Deadline-Constrained
WSNs,” In Proc. of IEEE INFOCOM, 2015.
acceptance ratio: 19.3%

Abstract—In deadline-constrained data aggregation in wireless
sensor networks (WSNs), the imposed sink deadline in an
interference-limited network hinders participation of all sensor
nodes in data aggregation. Thus, a subset of nodes can contribute
in aggregation and quality of aggregation (QoA) increases with
the growth of the number of participating nodes. Scheduling
the nodes’ transmissions is a central problem, which aims to
maximize the QoA, while satisfying the sink deadline, i.e., ontime
delivery of the sensed data to the sink node. Although the
previous studies have proposed optimal scheduling algorithms
to this problem given a particular aggregation tree, there is no
work on constructing optimal tree in this context. The underlying
aggregation tree can make a big difference on QoA since we
demonstrate that the ratio between the maximum achievable
QoAs of different trees could be as large as O(2^D), where D is
the sink deadline. In this paper, we cast an optimization problem
to address optimal tree construction for deadline-constrained
data aggregation in WSNs. The problem is combinatorial in
nature and difficult to solve as we prove its NP-hardness.
We employ Markov approximation framework and devise two
distributed algorithms with different computation overheads to
find bounded close-to-optimal solutions. Simulation experiments
in a set of representative randomly-generated scenarios show that
the proposed algorithms significantly improve QoA by 101% and
93% on average compared to the best, to our knowledge, existing
alternative methods.

##########################################################################################
• B. Alinia, H. Yousefi, M. S. Talebi, and A. Khonsari, ”Maximizing Quality of Aggregation in Delay-Constrained Wireless Sensor Networks”,
IEEE Communications Letters, 2013.

Abstract—In this letter, both the number of participating nodes
and spatial dispersion are incorporated to establish a bi-objective
optimization problem for maximizing the quality of aggregation
under interference and delay constraints in tree-based wireless
sensor networks (WSNs). The formulated problem is proved to
be NP-hard with respect to Weighted-sum scalarization and a
distributed heuristic aggregation scheduling algorithm, named
SDMAX, is proposed. Simulation results show that SDMAX
not only gives a close approximation of the Pareto-optimal
solution, but also outperforms the best, to our knowledge, existing
alternative proposed so far in the literature.