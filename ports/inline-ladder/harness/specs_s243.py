"""specs_s243.py - ladder thread batch 243: ZFFHERO::GetSpawnpointListFromTeam (team -> list name -> out)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _gsp(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    mgr = K.rnd(c, 0x20)
    e.w32(d, K.vt(c, 'database', {0x138: (0, lambda e2, a: (mgr, None, None))}, nslots=0x60))
    val = r.getrandbits(32)

    def fill(e2, a):
        e2.w32(a[1], val)      # the list manager writes the list handle through the out pointer
        e2.calllog.append(('listmgr88', a[0], K.nostack(a[1])))
        return 0, None, None
    e.w32(mgr, K.vt(c, 'listmgr', {0x88: (2, fill)}, nslots=0x100))
    return [r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 0xffffffff, r.getrandbits(32)])]


S(0x592350, 'ZFFHERO::GetSpawnpointListFromTeam', 'stdcall', None, ret='eax', gen=_gsp, note='batch243')
