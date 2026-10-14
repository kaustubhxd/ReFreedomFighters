"""specs_s872.py - area 50, batch 872: 0x519950 (GUESS name), thiscall, one stack arg, ret 4, no result.
Stood in: the accessor 0x5003d0 (returns a fixed record: a float and a state byte chosen per case), the object's vt +0x2d4
(a float in ST0, logged), the logger (0x700390) with a fake sink. The assert hook (0x7003b0) is null in some cases, set to a
logged stub in others (its call is the exe's, both runs)."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_crt_str


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    rec = rnd(c, 16)
    st = r.choice([0, 2, 2, 1, 3])
    e.w8(rec + 4, st)
    fv = r.uniform(-5.0, 5.0)

    other = rnd(c, 16)
    e.w8(other + 4, r.choice([0, 1, 2]))
    arg_ptr = {}

    def acc(e, rr):
        # the accessor answers the record for its object (ECX = the pointer at arg+8), another record otherwise
        o = e.reg('ecx')
        e.calllog.append(('acc.5003d0', e.arg32(0)))
        e.ret(eax=rec if o == arg_ptr.get('p') else other, argbytes=4)

    def v2d4(e, rr):
        e.calllog.append(('obj.2d4',))
        e.ret(eax=0, argbytes=0, st0=fv)

    def l20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    def s2c(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    def hookstub(e, rr):
        e.calllog.append(('assert.hook',))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x5003d0: acc})
    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: s2c})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: l20})
    e.w32(0x700390, logger)
    obj = vt_object(c, 0x40, {0x2d4: v2d4}, nslots=0x180, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, obj)
    arg = rnd(c, 0x40)
    inner = rnd(c, 0x40)
    e.w32(arg + 8, inner)                 # the accessor's object is the pointer stored at arg+8
    arg_ptr['p'] = inner
    # the exe's assert path jumps to an int3 when no hook is set, so the hook is always installed (a logged stub)
    hook_addr = e.stub_fn('assert_hook', hookstub)
    e.w32(0x7003b0, hook_addr)
    return [self, arg]


S(0x519950, 'Store519950 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch872')
