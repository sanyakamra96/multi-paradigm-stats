(* Calculate mean, median, and mode of a list of integers *)

let mean lst =
  match lst with
  | [] -> 0.0
  | _ ->
    let sum, count =
      List.fold_left (fun (s, c) x -> (s + x, c + 1)) (0, 0) lst
    in
    float_of_int sum /. float_of_int count

let median lst =
  let sorted = List.sort compare lst in
  match sorted with
  | [] -> 0.0
  | _ ->
    let len = List.length sorted in
    if len mod 2 = 1 then
      (* odd length *)
      let mid_idx = len / 2 in
      float_of_int (List.nth sorted mid_idx)
    else
      (* even length *)
      let mid1 = (len / 2) - 1 in
      let mid2 = len / 2 in
      let a = List.nth sorted mid1 in
      let b = List.nth sorted mid2 in
      (float_of_int (a + b)) /. 2.0

(* Build a frequency association list: (value, count) list *)
let frequencies lst =
  let update_freq freq_map x =
    let existing_count =
      try List.assoc x freq_map with Not_found -> 0
    in
    (x, existing_count + 1)
    :: List.remove_assoc x freq_map
  in
  List.fold_left update_freq [] lst

let mode lst =
  match lst with
  | [] -> None
  | _ ->
    let freq = frequencies lst in
    let best_val, best_count =
      List.fold_left
        (fun (bv, bc) (v, c) ->
          if c > bc then (v, c) else (bv, bc))
        (List.hd lst, 0)
        freq
    in
    Some (best_val, best_count)

let () =
  let data = [1; 2; 2; 3; 4; 4; 4; 5] in
  Printf.printf "Input data: [";
  List.iter (fun x -> Printf.printf "%d; " x) data;
  Printf.printf "]\n";

  let m = mean data in
  let med = median data in
  let mode_result = mode data in

  Printf.printf "Mean:   %.2f\n" m;
  Printf.printf "Median: %.2f\n" med;
  (match mode_result with
   | None -> Printf.printf "Mode:   none\n"
   | Some (v, c) ->
       Printf.printf "Mode:   %d (frequency %d)\n" v c)
