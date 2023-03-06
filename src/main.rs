mod mappacker;
use mappacker::FluxMapPacker;
fn main() {
    let args_nc = std::env::args();
    if args_nc.len() > 6 || args_nc.len() < 6 {
        println!("NOTE: For any names with spaces make sure to put it in double quotes(\"song name\")");
        println!("Usage: fluxpacker.exe <artist> <song_name> <mapper> <map_file> <mp3_file>");
        std::process::exit(0);
    }
    let args: Vec<String> = args_nc.collect();
    let packer = FluxMapPacker::new(&args[1], &args[2], &args[3], &args[4], &args[5]);
    packer.pack();
}
