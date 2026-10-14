"""specs_s249.py - ladder thread batch 249: ZFFHERO::CalcObjectsMatPos (item / object / global fallback paths)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K
import ops_kit as O
from pe_emu import f32


def _cmp(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    G2_ADDR = 0x70038c
    d = K.rnd(c, 0x100)
    e.w32(eng + 0x9b, d)
    gl = K.rnd(c, 0x40)
    e.w32(G2_ADDR, gl)
    g2ret = r.choice([0, 1, r.getrandbits(32)])
    e.w32(gl, K.vt(c, 'G2', {0xcc: (1, lambda e2, a: (K.nostack(0) if False else (g2ret), None, (K.nostack(a[0]),)))}, nslots=0x100))
    # the object tree: obj (a+0x44) can be an item (0x1e0 flag), or have a child o / o2
    flag_obj = r.choice([0, 1])
    y_flag = r.choice([0, 1])
    o2 = K.rnd(c, 0x80)
    o2_is_item = r.choice([0, 1])
    e.w32(o2, K.vt(c, 'o2', {0x2e0: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1])))),
                             0x98: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1]))))}, nslots=0x100))
    child_y = K.rnd(c, 0x80)
    o2 = child_y
    e.w32(child_y, K.vt(c, 'y', {0x1e0: (1, lambda e2, a: (y_flag, None, None)),
                                 0x2e0: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1])))),
                                 0x98: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1]))))}, nslots=0x100))
    obj = K.rnd(c, 0x80)
    has_child = r.choice([0, 1])
    o_ret = child_y if has_child else 0

    def o20(e2, a):
        return (o_ret if has_child else 0), None, None
    e.w32(obj, K.vt(c, 'obj', {
        0x1e0: (1, lambda e2, a: (flag_obj if a[0] == 0x1007d1 else (r.choice([0, 1]) if a[0] == 0x200074 else 0), None, (K.nostack(a[0]),))),
        0x20: (0, lambda e2, a: (o_ret, None, None)),
        0x2e0: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1])))),
        0x98: (2, lambda e2, a: (0, None, (K.nostack(a[0]), K.nostack(a[1])))),
        0x3a8: (2, lambda e2, a: (r.getrandbits(32), None, (K.nostack(a[0]), K.nostack(a[1])))),
        0x390: (1, lambda e2, a: (0, None, (a[0],)))}, nslots=0x100))
    # a (the action)
    act = K.rnd(c, 0x200)
    e.w32(act + 0x44, obj)
    e.w32(act + 0x106, r.getrandbits(32))
    mat = K.rnd(c, 0x40)
    pos = K.rnd(c, 0x20)
    for i in range(8):
        e.wf32(mat + 4 * i, c.fv())
    for i in range(3):
        e.wf32(pos + 4 * i, c.fv())
    # logger for the error line
    if g2ret == 0:
        lg = K.rnd(c, 0x20)
        pr = K.rnd(c, 0x20)
        e.w32(0x700390, lg)
        e.w32(lg, K.vt(c, 'logger', {0x20: (2, lambda e2, a: (pr, None, (K.nostack(a[0]), a[1])))}, nslots=0x100))
        def prn(e2, res):
            # cdecl: the caller pops the two arguments (add esp, 8), so this stub pops nothing
            e2.calllog.append(('printer', K.nostack(e2.arg32(1))))
            e2.ret(argbytes=0)
        prn_addr = e.stub_fn('printer2c', prn)
        e.w32(pr, e.fake_vtable('printer', 0x100, {0x2c: prn_addr}))
    hero = K.rnd(c, 0x100)
    def mreset(e2, res):
        e2.calllog.append(('mreset', K.nostack(e2.reg('ecx'))))
        e2.ret()
    e.hook(0x4de7a0, mreset)
    return [hero, act, mat, pos]


S(0x58c150, 'ZFFHERO::CalcObjectsMatPos', 'thiscall', None, ret='al', gen=_cmp, note='batch249')
