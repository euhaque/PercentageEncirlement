double ComputePercentageEncirclement(){
  
  double xyz[3];
  bool ret;
  
  typedef map<vtkIdType, int>::iterator it_type; map<vtkIdType, int> vertex_ids;
  int closestPointID=-1;
  
  vector<int> pointNeighbours;
  double pathSegmentHasScar=0;
  int order = _NEIGHBOURHOOD_IS_THIS_MANY_LEVELS_DEEP;
  
  for (int i=0;i<allShortestPaths.size();i++) {
    vtkIdList* vertices_in_shortest_path = vtkIdList::New(); vertices_in_shortest_path = allShortestPaths[i]->GetIdList();
  }
  
  for (it_type iterator = vertex_ids.begin(); iterator !=vertex_ids.end(); iterator++){
    GetNeighboursAroundPoint();
    if (IsThisNeighbourhoodCompleteWithScar(pointNeighbours))
      pathSegmentHasScar++;
    pointNeighbours.clear();
  }
  
  double tot_paths = vertex_ids.size();
  return (100*(pathSegmentHasScar/tot_paths));
}
