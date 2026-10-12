#!/usr/bin/env python3
"""Count GMS event class names (record +0x14 event list) per scene ZIP.
usage: python3 -I event_classes.py SCENES_DIR OUT.tsv [glob-substring]"""
import glob, os, struct, sys, tempfile, zipfile, collections
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import gms_world as G
def events(gms):
    sc = G.load_scene(gms); b = sc.body; cnt = collections.Counter(); cls = collections.Counter()
    for g in sc.geoms:
        cls[g['cls']] += 1
        eo = struct.unpack_from('<I', b, g['rec'] + 0x14)[0]
        if not eo or eo + 4 > len(b): continue
        n = struct.unpack_from('<I', b, eo)[0]
        if n > 64: continue
        for i in range(n):
            no = struct.unpack_from('<I', b, eo + 4 + 8 * i)[0]
            cnt[b[no:no + 48].split(b'\0')[0].decode('latin1')] += 1
    return cnt, cls
def main(sd, out, pat=''):
    with open(out, 'w') as o:
        for z in sorted(glob.glob(os.path.join(sd, '**', '*.ZIP'), recursive=True)):
            if pat not in z or os.path.basename(z).lower() == 'loader.zip': continue
            with tempfile.TemporaryDirectory() as td:
                zipfile.ZipFile(z).extractall(td)
                g = [os.path.join(r, f) for r, _, fs in os.walk(td) for f in fs if f.upper().endswith('.GMS')]
                if not g: continue
                c, k = events(g[0])
                for name, n in c.items(): o.write(f'{os.path.relpath(z, sd)}\tevent\t{name}\t{n}\n')
                for name, n in k.items(): o.write(f'{os.path.relpath(z, sd)}\tclass\t{hex(name)}\t{n}\n')
if __name__ == '__main__': main(*sys.argv[1:])
