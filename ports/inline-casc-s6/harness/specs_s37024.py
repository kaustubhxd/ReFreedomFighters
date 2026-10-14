"""specs_s37024.py - cascade s6 batch 37024: 0x4cb7f0 (recursive). Table slot 0x58 maps ids to objects (layered, so the recursion ends); list objects keep their own
iteration state (slot 0x4c starts, slot 0x5c returns the next item and writes the 'has item' flag through its pointer); this+0x54 slot 4 hands out blocks; 0x41e290 hooked;
this+0x48 is a list object with count slot 0x14 (sometimes wrong, so the assert hook path runs) and destructor slot 0."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _mklist(c, items, count=None):
    st = [0]

    def begin(em, k):
        st[0] = 0
        em.w32(em.arg32(0), 1)

    def nxt(em, k):
        i = st[0]
        st[0] += 1
        ok = i < len(items)
        em.w32(em.arg32(0), 1 if ok else 0)
        em.rets = items[i] if ok else 0
        return items[i] if ok else 0
    slots = {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=begin),
             0x5c: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: None, ret=None)}
    return slots, st, items


def _g4cb7f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    table = {}
    nid = [100]

    def list_obj(items, extra=None):
        st = [0]
        its = list(items)

        def begin(em, k):
            st[0] = 0
            em.w32(em.arg32(0), 1)

        def nxt_side(em, k):
            i = st[0]
            em.w32(em.arg32(0), 1 if i < len(its) else 0)

        def nxt_ret(em, k):
            i = st[0]
            st[0] += 1
            return its[i] if i < len(its) else 0
        slots = {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=begin),
                 0x5c: pystub(c, 1, this=True, nullflag=(0,), side=nxt_side, ret=nxt_ret)}
        slots.update(extra or {})
        return obj(c, 0x20, slots)

    def mkobj(layer_items, group):
        T = rnd(c, 0x40)
        e.w32(T + 0x23, 0x800001a if group else r.choice([0, 0x1234]))
        lst = list_obj(layer_items) if layer_items is not None else 0
        o = obj(c, 0x30, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 0, 0, 1, 0x100, 0x1ff]))})
        e.w32(o + 0xc, T)
        e.w32(o + 0x18, lst)
        return o

    def add(layer_items, group):
        i = nid[0]
        nid[0] += 1
        table[i] = mkobj(layer_items, group)
        return i
    leaves = [add(r.choice([None, []]), r.random() < 0.3) for _ in range(r.choice([2, 3, 4]))]
    mids = [add([r.choice(leaves) for _ in range(r.choice([0, 1, 2]))], r.random() < 0.7) for _ in range(r.choice([1, 2]))]
    topitems = [r.choice(leaves + mids + [9999]) for _ in range(r.choice([0, 1, 2, 4]))]
    top = add(topitems, False)
    if r.random() < 0.08:
        table[top] = 0
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0))}, table_size=0x20)
    blocks = [rnd(c, 0x20) + 8 for _ in range(8)]
    q = obj(c, 0x20, {0x4: pystub(c, 1, this=True, ret=lambda em, k: blocks[k % 8])})
    n2 = r.choice([0, 1, 2, 3, 5])
    items2 = [r.getrandbits(32) for _ in range(r.choice([n2, n2, n2, 0, 1, 6]))]
    cl = list_obj(items2, {0x14: pystub(c, 0, this=True, ret=n2), 0x0: pystub(c, 1, this=True)})
    b1, b2 = rnd(c, 0x40), rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: [b1, b2][k % 2])
    me = rnd(c, 0x80)
    e.w32(me + 0x54, q)
    e.w32(me + 0x48, cl if r.random() < 0.85 else 0)
    e.w32(me + 0x68, rnd(c, 0x40))
    return [me, top]


S(0x4cb7f0, 'GUESS expand group items and copy list', 'thiscall', None, ret=None, gen=_g4cb7f0, note='batch37024')
